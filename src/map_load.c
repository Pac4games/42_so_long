/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:49:40 by paugonca          #+#    #+#             */
/*   Updated: 2023/02/27 17:40:22 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
void	print_list(t_list *list)
{
	t_list *cursor;

	cursor = list;
	while (cursor)
	{
		ft_putstr_fd(cursor->content, 1);
		cursor = cursor->next;
	}
}
*/

static t_list	*map_get(char *path)
{
	int		fd;
	t_list	*map;
	char	*line;

	fd = open(path, O_RDONLY);
	map = 0;
	if (fd == -1)
		print_error("Failed to read map.\n");
	ft_putstr_fd("File opened successfully.\n", 1);
	line = get_next_line(fd);
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
	int		i;
	char	**res;
	t_list	*cursor;
	t_list	*map;

	p = 0;
	i = 0;
	map = map_get(path);
	cursor = map;
	while (cursor)
	{
		p++;
		cursor = cursor->next;
	}
	res = malloc((p + 1) * sizeof(char *));
	cursor = map;
	while (cursor)
	{
		res[i++] = cursor->content;
		cursor = cursor->next;
	}
	res[p] = 0;
	ft_lstclear(&map);
	return (res);
}
