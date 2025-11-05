/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:06:28 by angsanch          #+#    #+#             */
/*   Updated: 2025/11/06 00:41:59 by angsanch         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_engine	*e;
	t_data		*d;

	if (argc != 2)
		return (report_error("Exactly 1 parameter is expected.\n", 84));
	d = create_data(argv[1]);
	if (d == NULL)
		return (report_error("Could not read map.\n", 84));
	e = engine_init(1200, 600, "FDF by angsanch");
	d->disp.offset.x = 600;
	d->disp.offset.y = 300;
	rotate(&d->disp, M_PI / 4, 0, 0);
	rotate(&d->disp, 0, 0, M_PI / 4);
	if (e == NULL)
		return (report_error("Could not initialize window.\n", 84));
	engine_add_data(e, d, (void *)&destroy_data);
	engine_hook(e, hinternal_create(LOOP, base_loop, e, NULL));
	engine_hook(e, hinternal_create(KEY, close_on_esc, e, NULL));
	engine_hook(e, hinternal_create(KEY | MOUSE, modifiers, e, NULL));
	engine_hook(e, hinternal_create(KEY, perspective_keys, e, NULL));
	engine_hook(e, hinternal_create(SCROLL | CURSOR, perspective_mouse, e,
			NULL));
	mlx_loop(e->window);
	engine_stop(e);
	return (0);
}
