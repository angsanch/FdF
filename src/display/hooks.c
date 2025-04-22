/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 08:38:15 by angsanch          #+#    #+#             */
/*   Updated: 2025/04/22 09:40:08 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	perspective(t_hkind kind, t_hdata *data, void *param)
{
	t_engine	*e;
	t_data		*d;

	(void)kind;
	e = param;
	d = e->data;
	if (data->kind == KEY && data->key_data.action == MLX_PRESS)
	{
		if (data->key_data.key == MLX_KEY_UP)
			d->disp.y_offset += 10;
		if (data->key_data.key == MLX_KEY_DOWN)
			d->disp.y_offset -= 10;
		if (data->key_data.key == MLX_KEY_LEFT)
			d->disp.x_offset += 10;
		if (data->key_data.key == MLX_KEY_RIGHT)
			d->disp.x_offset -= 10;
		if (data->key_data.key == MLX_KEY_Z)
			d->disp.plane_distance ++;
		if (data->key_data.key == MLX_KEY_C && d->disp.plane_distance > 1)
			d->disp.plane_distance -= 1;
	}
	if (data->kind == SCROLL)
		d->disp.z_mod += data->ydelta / 10;
}
