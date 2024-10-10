/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 01:14:55 by angsanch          #+#    #+#             */
/*   Updated: 2024/10/11 01:58:23 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	read_lines(t_list *lines, int fd)
{
	char	*line;
	char	**splited;

	while (true)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		splited = my_split(line, ' ');
		free(line);
		if (splited == NULL || !list_append(lines, splited))
		{
			free_string_array(splited);
			return (0);
		}
	}
	return (1);
}

static t_list	*read_map(char *path)
{
	int		fd;
	t_list	*lines;
	int		status;

	lines = list_create((void *)&free_string_array);
	if (lines == NULL)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		list_destroy(lines);
		return (NULL);
	}
	status = read_lines(lines, fd);
	close(fd);
	gnl_flush();
	if (!status)
	{
		list_destroy(lines);
		return (NULL);
	}
	return (lines);
}

t_web	*map_to_web(char *path)
{
	t_web	*w;
	t_list	*lines;

	lines = read_map(path);
	if (lines == NULL)
		return (NULL);
	w = NULL;
	list_destroy(lines);
	return (w);
}
