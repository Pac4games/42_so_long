/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:49:40 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/01 11:23:58 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list	*map_get(char *path)
{
	int		fd;
	t_list	*map;
	char	*line;

	fd = open(path, O_RDONLY);
	map = 0;
	if (fd == -1)
		print_error("Failed to read map.\n");
	line = get_next_line(fd);
	if (!line)
		print_error("provided map is empty.\n");
	while (line)
	{
		ft_lstadd_back(&map, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (map);
}

char	**map_load(char *path)
{
	int		p;
	char	**res;
	t_list	*cursor;
	t_list	*map;

	p = 0;
	map = map_get(path);
	cursor = map;
	while (cursor)
	{
		p++;
		cursor = cursor->next;
	}
	res = malloc((p + 1) * sizeof(char *));
	if (!res)
		return (0);
	cursor = map;
	p = 0;
	while (cursor)
	{
		res[p++] = cursor->content;
		cursor = cursor->next;
	}
	res[p] = 0;
	ft_lstclear(&map);
	return (res);
}
