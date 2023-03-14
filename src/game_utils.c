/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:11:04 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/14 13:24:44 by paugonca         ###   ########.fr       */
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
	int	p;
	int	i;
	int	collet;

	p = 0;
	collet = 0;
	while (map[p])
	{
		i = 0;
		while (map[p][i])
			if (map[p][i++] == 'C')
				collet++;
		p++;
	}
	if (map[y][x] == '1')
		return (1);
	else if (map[y][x] == 'E' && collet)
		return (1);
	return (0);
}

static char	*get_player_sprite(int key, char *sprite)
{
	if (key == key_down || !sprite)
		return (PLAYER_DOWN);
	else if (key == key_up)
		return (PLAYER_UP);
	else if (key == key_left)
		return (PLAYER_LEFT);
	else if (key == key_right)
		return (PLAYER_RIGHT);
	return (sprite);
}

char	*get_exit_sprite(char **map)
{
	int	p;
	int	i;
	int	collet;

	p = 0;
	collet = 0;
	while (map[p])
	{
		i = 0;
		while (map[p][i])
			if (map[p][i++] == 'C')
				collet++;
		p++;
	}
	if (collet)
		return (EXIT_CLOSED);
	return (EXIT_OPEN);
}

int	player_move(int key, char **map)
{
	t_pos		pos;
	static char	*sprite;

	pos = get_player_pos(map);
	sprite = get_player_sprite(key, sprite);
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
	window_load(map, sprite, 0, 0);
	return (0);
}
