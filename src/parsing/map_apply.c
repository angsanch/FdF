/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:36:23 by angsanch          #+#    #+#             */
/*   Updated: 2025/04/25 02:11:48 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	parse_node(t_node *node, size_t x, size_t y, char *values)
{
	size_t	z_len;

	node->x = x;
	node->y = y;
	node->z = my_getnbr(values);
	z_len = my_intlen(node->z);
	if (my_strncmp(values + z_len, ",0x", 3) == 0)
	{
		node->color.value = \
			my_getnbr_base(values + z_len + 3, "0123456789abcdef");
	}
	else if (values[z_len] == '\0')
		node->color.value = 0xffffffff;
	else
		return (0);
	node->color.alpha = 0xff;
	return (1);
}

static int	apply_line(t_web *web, char **line, size_t width, size_t y)
{
	size_t	x;

	x = 0;
	while (line[x])
	{
		if (!parse_node(&web->node[(y * width) + x], x, y, line[x]))
			return (0);
		x ++;
	}
	return (1);
}

static int	add_connection(t_web *web, size_t a, size_t b)
{
	t_con	*c;

	c = malloc(sizeof(t_con) * 1);
	if (c == NULL)
		return (0);
	c->a = a;
	c->b = b;
	if (list_push(&web->connection, c))
		return (1);
	free(c);
	return (0);
}

static int	create_connections(t_web *web, size_t width, size_t height)
{
	size_t	x;
	size_t	y;
	size_t	current;

	y = 0;
	current = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (x + 1 < width)
				if (!add_connection(web, current, current + 1))
					return (0);
			if (y + 1 < height)
				if (!add_connection(web, current, current + width))
					return (0);
			current ++;
			x ++;
		}
		y ++;
	}
	return (1);
}

int	apply_map_lines(t_web *web, t_list *line_list, size_t width)
{
	char	***lines;
	int		status;
	size_t	y;

	lines = (char ***)list_export(line_list, NULL);
	if (lines == NULL)
		return (0);
	y = 0;
	status = 1;
	while (lines[y])
	{
		if (!apply_line(web, lines[y], width, y))
		{
			status = 0;
			break ;
		}
		y ++;
	}
	free(lines);
	return (status && create_connections(web, width, y));
}
