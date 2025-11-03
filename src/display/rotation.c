/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:16:41 by angsanch          #+#    #+#             */
/*   Updated: 2025/11/03 01:40:41 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// manually calculated matrix that rotates in the x y z axis respectively
static void	build_matrix(double *res, double x, double y, double z)
{
	double	xm[2];
	double	ym[2];
	double	zm[2];

	xm[0] = sin(x);
	xm[1] = cos(x);
	ym[0] = sin(y);
	ym[1] = cos(y);
	zm[0] = sin(z);
	zm[1] = cos(z);
	res[0] = ym[1] * zm[1];
	res[1] = -ym[1] * zm[0];
	res[2] = ym[0];
	res[3] = (xm[0] * ym[0] * zm[1]) + (xm[1] * zm[0]);
	res[4] = - (xm[0] * ym[0] * zm[0]) + (xm[1] * zm[1]);
	res[5] = -xm[0] * ym[1];
	res[6] = - (xm[1] * ym[0] * zm[1]) + (xm[0] * zm[0]);
	res[7] = (xm[1] * ym[0] * zm[0]) + (xm[0] * zm[1]);
	res[8] = xm[1] * ym[1];
}

static void	rotate_point(const double *mat, t_node *node)
{
	double	x;
	double	y;
	double	z;

	x = (node->x * mat[0]) + (node->y * mat[1]) + (node->z * mat[2]);
	y = (node->x * mat[3]) + (node->y * mat[4]) + (node->z * mat[5]);
	z = (node->x * mat[6]) + (node->y * mat[7]) + (node->z * mat[8]);
	node->x = x;
	node->y = y;
	node->z = z;
}

void	rotate(t_display *disp, double yz, double zx, double xy)
{
	double	mat[9];

	build_matrix(mat, yz, zx, xy);
	rotate_point(mat, &disp->xaxis);
	rotate_point(mat, &disp->yaxis);
	rotate_point(mat, &disp->zaxis);
}

void	rotation(t_data *data, double dx, double dy)
{
	rotate(&data->disp, dy / 180, -dx / 180, dx / 180);
}
