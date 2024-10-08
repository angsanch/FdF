/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:06:59 by angsanch          #+#    #+#             */
/*   Updated: 2024/10/04 04:53:59 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdint.h>

# include "basic.h"
# include "linked_list.h"
# include "my_printf.h"
# include "../minilibx/include/MLX42/MLX42.h"

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

typedef struct node
{
	union u_color	color;
}	t_node;

typedef struct web
{
	size_t	nodes;
	t_node	*node;
	uint8_t	*matrix;
}	t_web;

#endif
