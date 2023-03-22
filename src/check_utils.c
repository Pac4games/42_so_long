/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:16:02 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/20 12:14:48 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_shape(char **map, int p, int i)
{
	i = ft_strlen(map[0]);
	while (map[p])
		if (ft_strlen(map[p++]) != i)
			print_error("provided map is not rectangular.", map);
	if (p < 3 || i - 1 < 3)
		print_error("provided map is too small.", map);
}

static void	check_walls(char **map, int p, int i)
{
	while (map[p][i] && map[p][i] != '\n')
		if (map[p][i++] != '1')
			print_error("provided map not surrounded by walls.", map);
	p++;
	while (map[p])
	{
		i = ft_strlen(map[p]) - 2;
		if (map[p][0] != '1' || map[p][i] != '1')
			print_error("provided map not surrounded by walls.", map);
		p++;
	}
	p--;
	i = 0;
	while (map[p][i] && map[p][i] != '\n')
		if (map[p][i++] != '1')
			print_error("provided map not surrounded by walls.", map);
}

static void	check_other_errors(char **map, int player, int exit, int collet)
{
	if (player == 0)
		print_error("provided map does not contain a starting position.", map);
	else if (player > 1)
		print_error("provided map contains multiple starting positions.", map);
	if (exit == 0)
		print_error("provided map does not contain an exit.", map);
	else if (exit > 1)
		print_error("provided map contains multiple exits.", map);
	if (collet == 0)
		print_error("provided map does not contain any collets.", map);
}

static void	check_other(char **map, int p, int i)
{
	int	player;
	int	exit;
	int	collet;

	player = 0;
	exit = 0;
	collet = 0;
	while (map[p])
	{
		i = 0;
		while (map[p][i])
		{
			if (map[p][i] == 'P')
				player++;
			else if (map[p][i] == 'E')
				exit++;
			else if (map[p][i] == 'C')
				collet++;
			i++;
		}
		p++;
	}
	check_other_errors(map, player, exit, collet);
}

void	check_map(char **map)
{
	check_shape(map, 1, 0);
	check_walls(map, 0, 0);
	check_other(map, 1, 0);
	check_path(map, get_player_pos(map).x, get_player_pos(map).y);
}
