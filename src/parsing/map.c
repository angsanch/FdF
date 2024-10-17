/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 01:14:55 by angsanch          #+#    #+#             */
/*   Updated: 2024/10/17 06:24:19 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	read_lines(t_list *lines, int fd)
{
	char	*line;
	char	**splited;

	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		splited = my_split(line, ' ');
		free(line);
		if (splited == NULL || !list_append(lines, splited))
		{
			free_string_array(splited);
			return (0);
		}
	}
	return (1);
}

static t_list	*read_map(char *path)
{
	int		fd;
	t_list	*lines;
	int		status;

	lines = list_create((void *)&free_string_array);
	if (lines == NULL)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		list_destroy(lines);
		return (NULL);
	}
	status = read_lines(lines, fd);
	close(fd);
	gnl_flush();
	if (!status)
	{
		list_destroy(lines);
		return (NULL);
	}
	return (lines);
}

static int	check_lines_uniform_width(t_list *lines_list, size_t *width)
{
	char	***lines;
	int		status;
	size_t	i;

	lines = (char ***)list_export(lines_list, NULL);
	if (lines == NULL)
		return (0);
	*width = get_pointer_array_len(lines[0]);
	status = 1;
	i = 1;
	while (lines[i] && lines[0])
	{
		if (get_pointer_array_len(lines[i]) != *width)
		{
			status = 0;
			break ;
		}
		i ++;
	}
	free(lines);
	return (status);
}

static t_web	*web_from_lines(t_list *lines)
{
	t_web	*web;
	size_t	width;

	if (!check_lines_uniform_width(lines, &width))
		return (NULL);
	web = web_create(width * lines->len);
	if (!apply_map_lines(web, lines, width))
	{
		web_destroy(web);
		return (NULL);
	}
	return (web);
}

t_web	*map_to_web(char *path)
{
	t_web	*w;
	t_list	*lines;

	lines = read_map(path);
	if (lines == NULL)
		return (NULL);
	w = web_from_lines(lines);
	list_destroy(lines);
	return (w);
}
