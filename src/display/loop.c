/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:17:26 by angsanch          #+#    #+#             */
/*   Updated: 2025/04/22 02:28:53 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	base_loop(t_hkind kind, t_hdata *data, void *param)
{
	t_engine	*e;
	t_data		*d;

	(void)data;
	e = param;
	d = e->data;
	if (!(kind & LOOP))
		return ;
	engine_background(e,
		(union u_color){.red = 0, .green = 0, .blue = 0, .alpha = 0xff});
	engine_draw_line(e, (t_point){0, 0, {0}},
		(t_point){d->mx, d->my, {0xffffffff}});
}
