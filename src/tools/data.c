/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 04:41:53 by angsanch          #+#    #+#             */
/*   Updated: 2025/11/06 00:21:28 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	initialize_axis(t_node *axis, char name)
{
	axis->x = name == 'x';
	axis->y = name == 'y';
	axis->z = name == 'z';
}

static void	expand_borders(t_node *node, t_node *min, t_node *max)
{
	if (node->x < min->x)
		min->x = node->x;
	if (node->x > max->x)
		max->x = node->x;
	if (node->y < min->y)
		min->y = node->y;
	if (node->y > max->y)
		max->y = node->y;
	if (node->z < min->z)
		min->z = node->z;
	if (node->z > max->z)
		max->z = node->z;
}

static void	place_center(t_data *data)
{
	size_t	i;
	t_node	min;
	t_node	max;
	t_node	*n;

	if (data->web->nodes == 0)
		return ;
	n = data->web->node;
	min = (t_node){n[0].x, n[0].y, n[0].z, {0}};
	max = min;
	i = 1;
	while (i < data->web->nodes)
	{
		expand_borders(&n[i], &min, &max);
		i ++;
	}
	data->disp.center = (t_node){(max.x - min.x) / 2, (max.y - min.y) / 2,
		(max.z - min.z) / 2, {0}};
}

t_data	*create_data(char *path)
{
	t_data	*data;

	data = my_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->web = map_to_web(path);
	if (data->web == NULL)
	{
		destroy_data(data);
		return (NULL);
	}
	initialize_axis(&data->disp.xaxis, 'x');
	initialize_axis(&data->disp.yaxis, 'y');
	initialize_axis(&data->disp.zaxis, 'z');
	place_center(data);
	data->disp.center.z = 0;
	data->disp.plane_distance = 5;
	data->disp.z_mod = 1;
	return (data);
}

void	destroy_data(t_data *data)
{
	if (data == NULL)
		return ;
	web_destroy(data->web);
	free(data);
}
