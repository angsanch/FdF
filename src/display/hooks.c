/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 08:38:15 by angsanch          #+#    #+#             */
/*   Updated: 2025/11/05 22:49:39 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	modifiers(t_hkind kind, t_hdata *data, void *param)
{
	t_engine	*e;
	t_data		*d;

	(void)kind;
	e = param;
	d = e->data;
	if (data->kind == KEY)
	{
		if (data->key_data.key == MLX_KEY_LEFT_CONTROL)
			d->mod.ctrl = data->key_data.action == MLX_PRESS;
		if (data->key_data.key == MLX_KEY_LEFT_SHIFT)
			d->mod.shift = data->key_data.action == MLX_PRESS;
	}
	else if (data->kind == MOUSE)
	{
		if (data->mouse_press.button == MLX_MOUSE_BUTTON_LEFT)
			d->mod.lmb = data->mouse_press.action == MLX_PRESS;
		if (data->mouse_press.button == MLX_MOUSE_BUTTON_RIGHT)
			d->mod.rmb = data->mouse_press.action == MLX_PRESS;
	}
}

static void	traslation(t_data *data, double dx, double dy)
{
	data->disp.offset.x += dx;
	data->disp.offset.y += dy;
}

void	perspective_keys(t_hkind kind, t_hdata *data, void *param)
{
	t_engine	*e;
	t_data		*d;

	(void)kind;
	e = param;
	d = e->data;
	if (data->kind == KEY && data->key_data.action == MLX_PRESS)
	{
		if (data->key_data.key == MLX_KEY_UP)
			traslation(d, 0, 10);
		if (data->key_data.key == MLX_KEY_DOWN)
			traslation(d, 0, -10);
		if (data->key_data.key == MLX_KEY_LEFT)
			traslation(d, 10, 0);
		if (data->key_data.key == MLX_KEY_RIGHT)
			traslation(d, -10, 0);
		if (data->key_data.key == MLX_KEY_Z)
			d->disp.plane_distance ++;
		if (data->key_data.key == MLX_KEY_C && d->disp.plane_distance > 1)
			d->disp.plane_distance --;
	}
}

void	perspective_mouse(t_hkind __attribute__((unused))kind, t_hdata *data,
	void *param)
{
	t_data		*d;
	double		dmouse[2];

	d = ((t_engine *)param)->data;
	if (data->kind == SCROLL)
	{
		if (d->mod.ctrl)
		{
			if (data->ydelta > 0)
				d->disp.plane_distance ++;
			else if (data->ydelta < 0 && d->disp.plane_distance > 1)
				d->disp.plane_distance --;
		}
		else
			d->disp.z_mod += data->ydelta / 10;
	}
	if (data->kind == CURSOR)
	{
		dmouse[0] = data->mouse.x - data->pmouse.x;
		dmouse[1] = data->mouse.y - data->pmouse.y;
		if (d->mod.lmb)
			traslation(d, dmouse[0], dmouse[1]);
		if (d->mod.rmb)
			rotation(d, dmouse[0], dmouse[1]);
	}
}
