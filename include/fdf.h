/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:06:59 by angsanch          #+#    #+#             */
/*   Updated: 2025/04/22 02:28:35 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "basic.h"
# include "linked_list.h"
# include "my_printf.h"
# include "engine.h"

# include <math.h>
# include <stdint.h>

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

typedef struct data_container
{
	uint32_t	mx;
	uint32_t	my;
}	t_data;

t_web	*map_to_web(char *path);
int		apply_map_lines(t_web *web, t_list *lines, size_t width);

int		node_initialize(t_node *node);
void	node_delete(t_node *node);
t_web	*web_create(size_t nodes);
void	web_destroy(t_web *w);

void	base_loop(t_hkind kind, t_hdata *data, void *param);

#endif
