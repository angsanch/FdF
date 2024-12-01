/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:23:47 by angsanch          #+#    #+#             */
/*   Updated: 2024/12/01 02:53:10 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void	engine_mlx_bmouse(enum mouse_key button, enum action act,
				enum modifier_key mod, void *param)
{
	t_hdata				hd;
	t_engine			*engine;

	engine = param;
	my_memset(&hd, 0, sizeof(t_hdata));
	hd.mouse_press.button = button;
	hd.mouse_press.action = act;
	hd.mouse_press.modifier_key = mod;
	hd.kind = MOUSE;
	run_hooks(engine, &hd);
}

void	engine_mlx_mmouse(double x, double y, void *param)
{
	t_hdata					hd;
	t_engine				*engine;
	static bool				first = true;
	static struct s_pos2d	pmouse;

	engine = param;
	my_memset(&hd, 0, sizeof(t_hdata));
	if (first)
	{
		first = false;
		pmouse.x = x;
		pmouse.y = y;
	}
	my_memcpy(&hd.pmouse, &pmouse, sizeof(struct s_pos2d));
	hd.mouse.x = x;
	hd.mouse.y = y;
	my_memcpy(&pmouse, &hd.mouse, sizeof(struct s_pos2d));
	hd.kind = CURSOR;
	run_hooks(engine, &hd);
}
