/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:32:16 by angsanch          #+#    #+#             */
/*   Updated: 2025/10/29 02:21:01 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void	place_pixel(t_engine *e, int32_t x, int32_t y, union u_color col)
{
	if (x < 0 || x >= (int32_t)e->width || y < 0 || y >= (int32_t)e->height)
		return ;
	mlx_put_pixel(e->image, x, y, col.value);
}

static void	calculate_line(t_point *a, t_point *b, struct s_pos2d *line)
{
	line->x = (double)(b->y - a->y) / (double)(b->x - a->x);
	line->y = a->y - (line->x * a->x);
}

static void	draw_vertical(t_engine *engine, t_point *a, t_point *b)
{
	struct s_pos2d	line;
	int				y;
	int				x;

	calculate_line(a, b, &line);
	y = a->y;
	if (y < 0)
		y = 0;
	while (y <= b->y && (uint32_t)y < engine->height)
	{
		x = (y - line.y) / line.x;
		if (b->x - a->x == 0)
			x = a->x;
		place_pixel(engine, x, y, (union u_color){
			.red = my_map(y, (t_doublepair){a->y, b->y},
				(t_doublepair){a->color.red, b->color.red}),
			.green = my_map(y, (t_doublepair){a->y, b->y},
				(t_doublepair){a->color.green, b->color.green}),
			.blue = my_map(y, (t_doublepair){a->y, b->y},
				(t_doublepair){a->color.blue, b->color.blue}),
			.alpha = my_map(y, (t_doublepair){a->y, b->y},
				(t_doublepair){a->color.alpha, b->color.alpha}),
		});
		y ++;
	}
}

static void	draw_horizontal(t_engine *engine, t_point *a, t_point *b)
{
	struct s_pos2d	line;
	int				x;

	calculate_line(a, b, &line);
	x = a->x;
	if (x < 0)
		x = 0;
	while (x <= b->x && (uint32_t)x < engine->width)
	{
		place_pixel(engine, x, (line.x * x) + line.y, (union u_color){
			.red = my_map(x, (t_doublepair){a->x, b->x},
				(t_doublepair){a->color.red, b->color.red}),
			.green = my_map(x, (t_doublepair){a->x, b->x},
				(t_doublepair){a->color.green, b->color.green}),
			.blue = my_map(x, (t_doublepair){a->x, b->x},
				(t_doublepair){a->color.blue, b->color.blue}),
			.alpha = my_map(x, (t_doublepair){a->x, b->x},
				(t_doublepair){a->color.alpha, b->color.alpha}),
		});
		x ++;
	}
}

void	engine_draw_line(t_engine *engine, t_point a, t_point b)
{
	int	dx;
	int	dy;

	dx = abs(a.x - b.x);
	dy = abs(a.y - b.y);
	if (dx >= dy)
	{
		if (a.x <= b.x)
			draw_horizontal(engine, &a, &b);
		else
			draw_horizontal(engine, &b, &a);
	}
	else
	{
		if (a.y <= b.y)
			draw_vertical(engine, &a, &b);
		else
			draw_vertical(engine, &b, &a);
	}
}
