/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:49:40 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/06 14:44:57 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_open(char *path)
{
	int		p;
	int		i;
	char	*ext;

	p = 0;
	i = 0;
	ext = ".ber";
	while (path[p])
		p++;
	while (p > 0 && path[p] != '.')
		p--;
	while (path[p] && ext[i])
		if (path[p++] != ext[i++])
			print_error("provided file is not a \".ber\" map.");
	return (open(path, O_RDONLY));
}

static t_list	*map_get(char *path)
{
	int		fd;
	t_list	*map;
	char	*line;

	fd = map_open(path);
	map = 0;
	if (fd == -1)
		print_error("Failed to read map.");
	line = get_next_line(fd);
	if (!line)
		print_error("provided map is empty.");
	while (line)
	{
		ft_lstadd_back(&map, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (map);
}

char	**map_load(char *path, t_list *cursor)
{
	int		p;
	char	**res;
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

int	map_size(char **map, char axis)
{
	int	p;

	p = 0;
	if (axis == 'x')
		p = ft_strlen(map[0]) - 1;
	else if (axis == 'y')
	{
		while (map[p])
			p++;
	}
	return (p);
}

void	map_update(char **map, int x, int y)
{
	static int	steps;

	if (map[y][x] == 'C')
		ft_putstr_fd("Antidote collected.\n", 1);
	else if (map[y][x] == 'E')
		print_game_over("Exit reached, you win!\n");
	steps++;
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(steps, 1);
	ft_putchar_fd('\n', 1);
	map[y][x] = 'P';
}
