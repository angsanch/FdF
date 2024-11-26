/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 04:31:41 by angsanch          #+#    #+#             */
/*   Updated: 2024/11/26 14:07:52 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void	engine_mlx_scroll(double xdelta, double ydelta, void *param)
{
	t_hdata		hd;
	t_engine	*engine;

	engine = param;
	my_memset(&hd, 0, sizeof(t_hdata));
	hd.xdelta = xdelta;
	hd.ydelta = ydelta;
	hd.kind = SCROLL;
	run_hooks(engine, &hd);
}

void	engine_mlx_close(void *param)
{
	t_hdata		hd;
	t_engine	*engine;

	engine = param;
	my_memset(&hd, 0, sizeof(t_hdata));
	hd.kind = CLOSE;
	run_hooks(engine, &hd);
}

void	engine_mlx_resize(int32_t width, int32_t height, void *param)
{
	t_hdata		hd;
	t_engine	*engine;

	engine = param;
	my_memset(&hd, 0, sizeof(t_hdata));
	hd.width = width;
	hd.height = height;
	engine->width = width;
	engine->height = height;
	hd.kind = RESIZE;
	run_hooks(engine, &hd);
}

void	engine_mlx_key(mlx_key_data_t key_data, void *param)
{
	t_hdata		hd;
	t_engine	*engine;

	engine = param;
	my_memset(&hd, 0, sizeof(t_hdata));
	hd.key_data = key_data;
	hd.kind = KEY;
	run_hooks(engine, &hd);
}

void	engine_mlx_loop(void *param)
{
	t_hdata		hd;
	t_engine	*engine;

	engine = param;
	my_memset(&hd, 0, sizeof(t_hdata));
	hd.kind = LOOP;
	run_hooks(engine, &hd);
}
