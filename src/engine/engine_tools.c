/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:23:38 by angsanch          #+#    #+#             */
/*   Updated: 2024/11/19 04:27:41 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

t_engine	*engine_init(size_t width, size_t height, char *title)
{
	t_engine	*engine;

	engine = my_calloc(1, sizeof(t_engine));
	if (engine == NULL)
		return (NULL);
	engine->window = mlx_init(width, height, title, true);
	engine->width = width;
	engine->height = height;
	engine->buffer = mlx_new_image(engine->window, width, height);
	if (engine->buffer == NULL || !initialize_hooks(engine))
	{
		engine_stop(engine);
		return (NULL);
	}
	return (engine);
}

void	engine_stop(t_engine *engine)
{
	if (engine == NULL)
		return ;
	mlx_delete_image(engine->window, engine->buffer);
	mlx_delete_image(engine->window, engine->current);
	mlx_close_window(engine->window);
	mlx_terminate(engine->window);
	list_delete(&engine->hook);
	free(engine);
}

int	engine_hook(t_engine *engine, t_hinternal *hi)
{
	if (hi == NULL)
		return (0);
	if (!list_push(&engine->hook, hi))
	{
		hinternal_destroy(hi);
		return (0);
	}
	return (1);
}
