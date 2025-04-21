/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:06:28 by angsanch          #+#    #+#             */
/*   Updated: 2025/04/22 00:38:20 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	close_on_esc(t_hkind kind, t_hdata *data, void *param)
{
	t_engine	*e;

	(void)kind;
	e = param;
	if (data->kind == KEY && data->key_data.key == MLX_KEY_ESCAPE && \
		data->key_data.action == MLX_RELEASE)
		engine_close(e);
}

static void	new_hook_res(t_hkind kind, t_hdata *data, void *param)
{
	t_engine *e = param;

	(void)kind;
	(void)data;
	(void)param;
	if (data->kind & CURSOR) {
		printf("%f %f %f %f\n", data->mouse.x, data->mouse.y, data->pmouse.x, data->pmouse.y);
		mlx_put_pixel(e->image, data->mouse.x, data->mouse.y, (union u_color){.red=255, .green=255, .blue=255, .alpha=0xa0}.value);
	}
	if (data->kind & MOUSE)
		printf("%d %d %d\n", data->mouse_press.button, data->mouse_press.modifier_key, data->mouse_press.action);
	//printf("%u %u\n", e->width, e->height);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_engine	*e = engine_init(1200, 600, "hello world");

	engine_hook(e, hinternal_create(MOUSE | CURSOR, new_hook_res, e, NULL));
	engine_hook(e, hinternal_create(KEY, close_on_esc, e, NULL));
	printf("%f\n", my_map(75, (t_doublepair){50, 100}, (t_doublepair){1000, 2000}));
	engine_background(e, (union u_color){.red=0, .green=0, .blue=0, .alpha=0xff});
	engine_draw_line(e, (t_point){-100, 100, {0xff0000ff}}, (t_point){300, 600, {0x0000ffff}});
	mlx_loop(e->window);
	engine_stop(e);
	return (0);
}
