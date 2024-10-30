/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:06:28 by angsanch          #+#    #+#             */
/*   Updated: 2024/10/30 04:33:48 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void print_con(void *con, void __attribute__((unused))*nul)
{
	t_con *c = con;
	my_printf("%zd %zd\n", c->a,  c->b);
}

int	main(int argc, char **argv)
{
	t_web	*web = map_to_web(argv[1]);

	list_iter(&web->connection, &print_con, NULL);
	my_printf("%zd\n", web->connection.first);
	(void)argc;
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
