/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:17:26 by angsanch          #+#    #+#             */
/*   Updated: 2025/11/05 23:08:36 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	process_node(t_node *p, t_display *d)
{
	t_node	n;

	n.x = ((p->x - d->center.x) * d->xaxis.x) + \
		((p->y - d->center.y) * d->xaxis.y) + \
		((p->z - d->center.z) * d->xaxis.z * d->z_mod);
	n.z = ((p->x - d->center.x) * d->zaxis.x) + \
		((p->y - d->center.y) * d->zaxis.y) + \
		((p->z - d->center.z) * d->zaxis.z * d->z_mod);
	return ((t_point){
		n.x * d->plane_distance + d->offset.x,
		- n.z * d->plane_distance + d->offset.y,
		p->color,
	});
}

static void	draw_connection(t_con *con, t_engine *e)
{
	t_node	*n[2];
	t_data	*d;

	d = e->data;
	n[0] = &d->web->node[con->a];
	n[1] = &d->web->node[con->b];
	engine_draw_line(e, process_node(n[0], &d->disp),
		process_node(n[1], &d->disp));
}

static void	draw_web(t_engine *e)
{
	t_data	*d;

	d = e->data;
	list_iter(&d->web->connection, (void *)&draw_connection, e);
}

void	base_loop(t_hkind kind, t_hdata *data, void *param)
{
	t_engine	*e;
	t_data		*d;

	(void)data;
	e = param;
	d = e->data;
	(void)d;
	if (!(kind & LOOP))
		return ;
	engine_background(e,
		(union u_color){.red = 0, .green = 0, .blue = 0, .alpha = 0xff});
	draw_web(e);
}
