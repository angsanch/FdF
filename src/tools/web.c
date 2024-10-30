/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   web.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 00:10:19 by angsanch          #+#    #+#             */
/*   Updated: 2024/10/30 04:31:27 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_web	*web_create(size_t nodes)
{
	t_web	*w;

	w = my_calloc(1, sizeof(t_web));
	if (w == NULL)
		return (NULL);
	w->node = malloc(sizeof(t_node) * nodes);
	if (w->node == NULL)
	{
		free(w->node);
		return (NULL);
	}
	list_initialize(&w->connection, &free);
	w->nodes = 0;
	while (w->nodes < nodes)
	{
		if (!node_initialize(&w->node[w->nodes]))
		{
			web_destroy(w);
			return (NULL);
		}
		w->nodes ++;
	}
	return (w);
}

void	web_destroy(t_web *w)
{
	size_t	i;

	if (w == NULL)
		return ;
	i = 0;
	while (i < w->nodes)
	{
		node_delete(&w->node[i]);
		i ++;
	}
	list_delete(&w->connection);
	free(w->node);
	free(w);
}
