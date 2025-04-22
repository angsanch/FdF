/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:23:38 by angsanch          #+#    #+#             */
/*   Updated: 2025/04/22 02:19:23 by angsanch         ###   ########.fr       */
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
	engine->image = mlx_new_image(engine->window, width, height);
	if (engine->image == NULL || !initialize_hooks(engine))
	{
		engine_stop(engine);
		return (NULL);
	}
	mlx_image_to_window(engine->window, engine->image, 0, 0);
	return (engine);
}

void	engine_stop(t_engine *engine)
{
	if (engine == NULL)
		return ;
	mlx_delete_image(engine->window, engine->image);
	mlx_close_window(engine->window);
	mlx_terminate(engine->window);
	list_delete(&engine->hook);
	if (engine->data && engine->data_destroy)
		engine->data_destroy(engine->data);
	free(engine);
}

void	engine_close(t_engine *engine)
{
	mlx_close_window(engine->window);
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

void	engine_add_data(t_engine *engine, void *data, void (*destroy)(void *))
{
	engine->data = data;
	engine->data_destroy = destroy;
}
