/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 04:41:53 by angsanch          #+#    #+#             */
/*   Updated: 2025/04/27 18:35:19 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	data->disp.x_offset = 600;
	data->disp.y_offset = 300;
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
