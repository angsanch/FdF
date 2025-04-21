/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:29:55 by angsanch          #+#    #+#             */
/*   Updated: 2025/04/21 20:10:23 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	engine_background(t_engine *engine, union u_color color)
{
	size_t			width;
	size_t			height;
	union u_color	*buff;
	size_t			i;

	width = engine->image->width;
	height = engine->image->height;
	buff = (union u_color *)engine->image->pixels;
	i = 0;
	while (i < width * height)
	{
		buff[i].value = color.value;
		i ++;
	}
}
