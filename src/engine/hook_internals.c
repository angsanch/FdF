/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_internals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 05:20:47 by angsanch          #+#    #+#             */
/*   Updated: 2024/11/19 04:21:06 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

t_hinternal	*hinternal_create(t_hkind kind, t_hfunc func, void *param,
	void (*destroy_param)(void *))
{
	t_hinternal	*hin;

	hin = my_calloc(1, sizeof(t_hinternal));
	if (hin == NULL)
		return (NULL);
	hin->kind = kind;
	hin->func = func;
	hin->param = param;
	hin->destroy_param = destroy_param;
	return (hin);
}

void	hinternal_destroy(t_hinternal *hin)
{
	if (hin == NULL)
		return ;
	if (hin->destroy_param)
		hin->destroy_param(hin->param);
	free(hin);
}

static void	run_hook(void *internals_void, void *data_void)
{
	t_hinternal	*hi;
	t_hdata		*hd;

	hi = internals_void;
	hd = data_void;
	if (!(hi->kind & hd->kind))
		return ;
	hi->func(hd->kind, hd, hi->param);
}

void	run_hooks(t_engine *engine, t_hdata *hd)
{
	list_iter(&engine->hook, &run_hook, hd);
}

int	initialize_hooks(t_engine *engine)
{
	list_initialize(&engine->hook, (void (*)(void *)) & hinternal_destroy);
	mlx_scroll_hook(engine->window, &engine_mlx_scroll, engine);
	mlx_close_hook(engine->window, &engine_mlx_close, engine);
	mlx_resize_hook(engine->window, &engine_mlx_resize, engine);
	mlx_key_hook(engine->window, &engine_mlx_key, engine);
	return (mlx_loop_hook(engine->window, &engine_mlx_loop, engine) == true);
}
