/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:16:46 by angsanch          #+#    #+#             */
/*   Updated: 2024/11/19 04:36:46 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "../minilibx/include/MLX42/MLX42.h"
# include "basic.h"
# include "linked_list.h"

# include <stdint.h>

union u_color
{
	uint32_t	value;
	struct
	{
		uint8_t	blue;
		uint8_t	green;
		uint8_t	red;
		uint8_t	alpha;
	};
};

enum e_hooks
{
	NON		= 0b00000,
	SCROLL	= 0b00001,
	CLOSE	= 0b00010,
	RESIZE	= 0b00100,
	KEY		= 0b01000,
	LOOP	= 0b10000,
};

typedef uint8_t	t_hkind;

typedef struct hook_data
{
	double			xdelta;
	double			ydelta;
	int32_t			width;
	int32_t			height;
	mlx_key_data_t	key_data;
	t_hkind			kind;
}	t_hdata;

typedef void	(*t_hfunc)(t_hkind kind, t_hdata *data, void *param);

typedef struct hook_internals
{
	t_hfunc	func;
	void	*param;
	void	(*destroy_param)(void *);
	t_hkind	kind;
}	t_hinternal;

typedef struct engine
{
	mlx_t		*window;
	mlx_image_t	*buffer;
	mlx_image_t	*current;
	t_list		hook;
	size_t		width;
	size_t		height;
}	t_engine;

t_engine	*engine_init(size_t width, size_t height, char *title);
void		engine_stop(t_engine *engine);

int			engine_hook(t_engine *engine, t_hinternal *hi);

t_hinternal	*hinternal_create(t_hkind kind, t_hfunc func, void *param,
				void (*destroy_param)(void *));
void		hinternal_destroy(t_hinternal *hin);
int			initialize_hooks(t_engine *engine);
void		run_hooks(t_engine *engine, t_hdata *hd);

void		engine_mlx_scroll(double xdelta, double ydelta, void *param);
void		engine_mlx_close(void *param);
void		engine_mlx_resize(int32_t width, int32_t height, void *param);
void		engine_mlx_key(mlx_key_data_t key_data, void *param);
void		engine_mlx_loop(void *param);

#endif