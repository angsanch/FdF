/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:06:59 by angsanch          #+#    #+#             */
/*   Updated: 2024/10/30 04:18:36 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdint.h>

# include "basic.h"
# include "linked_list.h"
# include "my_printf.h"
# include "../minilibx/include/MLX42/MLX42.h"

union u_color
{
	uint32_t	value;
	struct
	{
		uint8_t	blue;
		uint8_t	green;
		uint8_t	red;
		uint8_t	alpha;
	};
};

typedef struct node
{
	ssize_t			x;
	ssize_t			y;
	ssize_t			z;
	union u_color	color;
}	t_node;

typedef struct connection
{
	size_t	a;
	size_t	b;
}	t_con;

typedef struct web
{
	size_t	nodes;
	t_node	*node;
	t_list	connection;
	size_t	changes;
}	t_web;

t_web	*map_to_web(char *path);
int		apply_map_lines(t_web *web, t_list *lines, size_t width);

int		node_initialize(t_node *node);
void	node_delete(t_node *node);
t_web	*web_create(size_t nodes);
void	web_destroy(t_web *w);

#endif
