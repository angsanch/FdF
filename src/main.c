/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:06:28 by angsanch          #+#    #+#             */
/*   Updated: 2024/11/19 04:36:02 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	new_hook(t_hkind kind, t_hdata *data, void *param)
{
	printf("%d %p\n%f %f %d %d %d\n", kind, param, data->xdelta, data->ydelta, data->width, data->height, data->kind);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_engine	*e = engine_init(1200, 600, "hello world");

	engine_hook(e, hinternal_create(RESIZE | SCROLL | KEY | CLOSE, new_hook, NULL, &free));
	mlx_loop(e->window);
	engine_stop(e);
	return (0);
}
