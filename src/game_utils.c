/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:11:04 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/06 14:39:25 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	get_player_pos(char **map)
{
	int		y;
	int		x;
	t_pos	player_pos;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				player_pos.x = x;
				player_pos.y = y;
				break ;
			}
			x++;
		}
		if (map[y][x] == 'P')
			break ;
		y++;
	}
	return (player_pos);
}

int	player_collision(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return (1);
	return (0);
}

int	player_move(int key, char **map)
{
	t_pos	pos;

	pos = get_player_pos(map);
	map[pos.y][pos.x] = '0';
	if (key == key_up && !player_collision(map, pos.x, pos.y - 1))
		map_update(map, pos.x, pos.y - 1);
	else if (key == key_down && !player_collision(map, pos.x, pos.y + 1))
		map_update(map, pos.x, pos.y + 1);
	else if (key == key_left && !player_collision(map, pos.x - 1, pos.y))
		map_update(map, pos.x - 1, pos.y);
	else if (key == key_right && !player_collision(map, pos.x + 1, pos.y))
		map_update(map, pos.x + 1, pos.y);
	else
		map[pos.y][pos.x] = 'P';
	window_load(map, 0, 0);	
	return (0);
}
