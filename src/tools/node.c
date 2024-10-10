/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 00:03:42 by angsanch          #+#    #+#             */
/*   Updated: 2024/10/11 01:06:27 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	node_initialize(t_node *node)
{
	my_memset(node, 0, sizeof(t_node));
	node->color.value = 0xffffffff;
	return (1);
}

void	node_delete(t_node __attribute__((unused))*node)
{
}
