/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:16:02 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/04 23:13:12 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_shape(char **map, int p, int i)
{
	i = ft_strlen(map[0]);
	while (map[p])
		if (ft_strlen(map[p++]) != i)
			print_error("provided map is not rectangular.");
	if (p < 3 || i - 1 < 3)
		print_error("provided map is too small.");
}

static void	check_walls(char **map, int p, int i)
{
	while (map[p][i] && map[p][i] != '\n')
		if (map[p][i++] != '1')
			print_error("provided map not surrounded by walls.");
	p++;
	while (map[p])
	{
		i = ft_strlen(map[p]) - 2;
		if (map[p][0] != '1' || map[p][i] != '1')
			print_error("provided map not surrounded by walls.");
		p++;
	}
	p--;
	i = 0;
	while (map[p][i] && map[p][i] != '\n')
		if (map[p][i++] != '1')
			print_error("provided map not surrounded by walls.");
}

static void	check_other_errors(int player, int exit, int collectible)
{
	if (player == 0)
		print_error("provided map does not contain a starting position.");
	else if (player > 1)
		print_error("provided map contains multiple starting positions.");
	if (exit == 0)
		print_error("provided map does not contain an exit.");
	else if (exit > 1)
		print_error("provided map contains multiple exits.");
	if (collectible == 0)
		print_error("provided map does not contain any collectibles.");
}

static void	check_other(char **map, int p, int i)
{
	int	player;
	int	exit;
	int	collectible;

	player = 0;
	exit = 0;
	collectible = 0;
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
				collectible++;
			i++;
		}
		p++;
	}
	check_other_errors(player, exit, collectible);
}

void	check_map(char **map)
{
	check_shape(map, 1, 0);
	check_walls(map, 0, 0);
	check_other(map, 1, 0);
}
