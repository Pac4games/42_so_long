/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:16:02 by paugonca          #+#    #+#             */
/*   Updated: 2023/02/28 23:44:54 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_shape(char **map, int p, int i)
{
	i = ft_strlen(map[0]);
	while (map[p])
		if (ft_strlen(map[p++]) != i)
			return (0);
	if (p < 3 || i - 1 < 3)
		return (0);
	return (1);
}

static int	check_walls(char **map, int p, int i)
{
	while (map[p][i] && map[p][i] != '\n')
		if (map[p][i++] != '1')
			return (0);
	p++;
	while (map[p])
	{
		i = ft_strlen(map[p]) - 2;
		if (map[p][0] != '1' || map[p][i] != '1')
			return (0);
		p++;
	}
	p--;
	i = 0;
	while (map[p][i] && map[p][i] != '\n')
		if (map[p][i++] != '1')
			return (0);
	return (1);
}

static int	check_player(char **map, int p, int i)
{
	int	player;

	player = 0;
	while (map[p])
	{
		i = 0;
		while (map[p][i])
			if (map[p][i++] == 'P')
				player++;
		p++;
	}
	if (player != 1)
		return (0);
	return (1);
}

static int	check_exit(char **map, int p, int i)
{
	int	exit;

	exit = 0;
	while (map[p])
	{
		i = 0;
		while (map[p][i])
			if (map[p][i++] == 'E')
				exit++;
		p++;
	}
	if (exit != 1)
		return (0);
	return (1);
}

void	check_map(char **map)
{
	if (!check_shape(map, 0, 0))
		print_error("provided map is not rectangular or too small.\n");
	else if (!check_walls(map, 0, 0))
		print_error("provided map not surrounded by walls.\n");
	else if (!check_player(map, 1, 0))
		print_error("provided map has zero or multiple starting positions.\n");
	else if (!check_exit(map, 1, 0))
		print_error("provided map contains zero or multiple exits\n");
	ft_putstr_fd("The provided map is valid.\n", 1);
}
