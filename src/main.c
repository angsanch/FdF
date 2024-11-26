/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:06:28 by angsanch          #+#    #+#             */
/*   Updated: 2024/11/26 14:11:55 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	new_hook_loop(t_hkind kind, t_hdata *data, void *param)
{
	t_engine	*e;

	(void)kind;
	(void)data;
	e = param;
	printf("%u %u\n", e->width, e->height);
}

static void	new_hook_res(t_hkind kind, t_hdata *data, void *param)
{
	(void)kind;
	(void)data;
	(void)param;
	printf("resize\n");
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_engine	*e = engine_init(1200, 600, "hello world");

	engine_hook(e, hinternal_create(RESIZE, new_hook_res, e, NULL));
	engine_hook(e, hinternal_create(LOOP, new_hook_loop, e, NULL));
	mlx_loop(e->window);
	engine_stop(e);
	return (0);
}
