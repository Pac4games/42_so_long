/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:35:20 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/17 14:50:35 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "so_long.h"

static int	count_free_space(char **map)
{
	int x;
	int y;
	int count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	check_path(char **map)
{
	t_pos	pos;
	int		space;
	int		count;

	pos = get_player_pos(map);
	space = count_free_space(map);
	count = 0;
	while (count != space)
	{
		if (map[pos.y][pos.x + 1] != '1')
			pos.x++;
		else if (map[pos.y][pos.x - 1] != '1')
			pos.x--;
		else if (map[pos.y + 1][pos.x] != '1')
			pos.y++;
		else if (map[pos.y - 1][pos.x] != '1')
			pos.y--;
		if (map[pos.x][pos.y] == 'E')
			break ;
		count++;
	}
	if (count < space)
		print_error("provided map does not contain a valid path to the exit.");
}
*/
