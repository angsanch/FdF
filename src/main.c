/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:06:28 by angsanch          #+#    #+#             */
/*   Updated: 2024/10/17 06:20:23 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(void)
{
	t_web	*web = map_to_web("maps/mars.fdf");

	if (web == NULL)
		return (84);
	web_destroy(web);
	return (0);
	/*mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(1200, 600, "42Balls", true);
	(void)mlx;
	uint32_t a = 0xaabbccdd;
	my_showmem((char *)&a, 4);
	while (1);*/
}
