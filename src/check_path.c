/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:35:20 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/18 11:18:52 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_collet(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			if (map[y][x++] == 'C')
				count++;
		y++;
	}
	return (count);
}
/*
static void	find_path(char **tmp, int x, int y, int collet)
{
	if (tmp[y][x] == 'C' || tmp[y][x] == 'E')
		collet++;
	tmp[y][x] = 'R';
	if (tmp[y][x + 1] != '1' || tmp[y][x + 1] != 'R')
		find_path(tmp, x + 1, y, collet);
	if (tmp[y][x - 1] != '1' || tmp[y][x - 1] != 'R')
		find_path(tmp, x - 1, y, collet);
	if (tmp[y + 1][x] != '1' || tmp[y + 1][x] != 'R')
		find_path(tmp, x, y + 1, collet);
	if (tmp[y - 1][x] != '1' || tmp[y - 1][x] != 'R')
		find_path(tmp, x, y - 1, collet);
}
*/

void	find_path(char **tmp, int x, int y, int *c)
{
	*c += ('E' == tmp[y][x] || 'C' == tmp[y][x]);
	tmp[y][x] = 'R';
	if ('1' != tmp[y][x + 1] && 'R' != tmp[y][x + 1])
		find_path(tmp, x + 1, y, c);
	if ('1' != tmp[y][x - 1] && 'R' != tmp[y][x - 1])
		find_path(tmp, x - 1, y, c);
	if ('1' != tmp[y + 1][x] && 'R' != tmp[y + 1][x])
		find_path(tmp, x, y + 1, c);
	if ('1' != tmp[y - 1][x] && 'R' != tmp[y - 1][x])
		find_path(tmp, x, y - 1, c);
}

void	check_path(char **map, int x, int y)
{
	char	**tmp;
	int		p;
	int		collet;
	
	p = 0;
	collet = 0;
	while (map[p])
		p++;
	tmp = malloc(p * sizeof(char *) + 1);
	p = 0;
	while (map[p])
	{
		tmp[p] = ft_strdup(map[p]);
		p++;
	}
	if (!tmp)
		return ;
	find_path(tmp, x, y, &collet);
	if (collet != (count_collet(map) + 1))
		print_error("provided map does not contain a valid path.");
}
