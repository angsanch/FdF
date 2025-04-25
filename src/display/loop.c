/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:17:26 by angsanch          #+#    #+#             */
/*   Updated: 2025/04/23 17:34:00 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	process_node(t_node *n, t_display *d)
{
	const double	cos30 = 0.866;
	const double	sin30 = 0.5;

	return ((t_point){
		(cos30 * n->x - cos30 * n->y) * d->plane_distance + d->x_offset,
		(sin30 * n->x + sin30 * n->y - n->z * d->z_mod) * \
			d->plane_distance + d->y_offset,
		n->color,
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
