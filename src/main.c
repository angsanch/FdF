/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:06:28 by angsanch          #+#    #+#             */
/*   Updated: 2024/11/15 04:09:55 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_engine	*e = engine_init(1200, 600, "hello world");

	mlx_loop(e->window);
	engine_stop(e);
	return (0);
}
