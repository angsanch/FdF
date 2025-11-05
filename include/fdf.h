/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:06:59 by angsanch          #+#    #+#             */
/*   Updated: 2025/11/06 00:38:24 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "basic.h"
# include "linked_list.h"
# include "my_printf.h"
# include "engine.h"

# define _USE_MATH_DEFINES
# include <math.h>
# include <stdint.h>

typedef struct node
{
	double			x;
	double			y;
	double			z;
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
}	t_web;

typedef struct display_data
{
	t_node		xaxis;
	t_node		yaxis;
	t_node		zaxis;
	t_node		offset;
	t_node		center;
	double		z_mod;
	uint32_t	plane_distance;
}	t_display;

typedef struct modifiers_status
{
	bool	ctrl;
	bool	shift;
	bool	rmb;
	bool	lmb;
}	t_mod;

typedef struct data_container
{
	t_display	disp;
	t_mod		mod;
	t_web		*web;
}	t_data;

t_data	*create_data(char *path);
void	destroy_data(t_data *data);

t_web	*map_to_web(char *path);
int		apply_map_lines(t_web *web, t_list *lines, size_t width);

int		node_initialize(t_node *node);
void	node_delete(t_node *node);
t_web	*web_create(size_t nodes);
void	web_destroy(t_web *w);

void	base_loop(t_hkind kind, t_hdata *data, void *param);
void	perspective_keys(t_hkind kind, t_hdata *data, void *param);
void	perspective_mouse(t_hkind kind, t_hdata *data, void *param);
void	modifiers(t_hkind kind, t_hdata *data, void *param);

void	rotate(t_display *disp, double yz, double zx, double xy);
void	rotation(t_data *data, double dx, double dy);

#endif
