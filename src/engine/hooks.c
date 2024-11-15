/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 04:31:41 by angsanch          #+#    #+#             */
/*   Updated: 2024/11/15 05:04:36 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/engine.h"

void	engine_hook(t_engine *engine, void (*func)(t_engine *))
{
	static void	(*hookers[])(mlx_t *mlx, void *, void *param) = {NULL,
		&mlx_scroll_hook, &mlx_close_hook, &mlx_resize_hook, &mlx_key_hook,
		&mlx_loop_hook};
}
