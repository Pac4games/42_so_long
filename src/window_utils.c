/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:35:03 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/01 22:18:56 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	window_set_tile(char tile, int x, int y)
{
	mlx_put_image_to_window((*window()).mlx, (*window()).win, (*window()).img,
			x * 64, y * 64);
}

static void	window_load(char **map, int p, int i)
{
	while (map[p])
	{
		i = 0;
		while (map[p][i])
		{
			if (map[p][i] == '1')
				(*window()).img = mlx_xpm_file_to_image((*window()).mlx, WALL,
						&(*window()).img_x, &(*window()).img_y);
			else if (map[p][i] == '0')
				(*window()).img = mlx_xpm_file_to_image((*window()).mlx, FLOOR,
						&(*window()).img_x, &(*window()).img_y);
			else if (map[p][i] == 'P')
				(*window()).img = mlx_xpm_file_to_image((*window()).mlx,
						PLAYER_S, &(*window()).img_x, &(*window()).img_y);
			else if (map[p][i] == 'C')
				(*window()).img = mlx_xpm_file_to_image((*window()).mlx,
						COLLECTIBLE, &(*window()).img_x, &(*window()).img_y);
			else if (map[p][i] == 'E')
				(*window()).img = mlx_xpm_file_to_image((*window()).mlx,
						EXIT, &(*window()).img_x, &(*window()).img_y);
			else if (map[p][i] != '\n')
				print_error("invalid object detected in map.");
			window_set_tile(map[p][i], i, p);
			i++;
		}
		p++;
	}
}

void	window_create(char **map)
{
	(*window()).size_x = map_size(map, 'x');
	(*window()).size_y = map_size(map, 'y');
	(*window()).mlx = mlx_init();
	(*window()).win = mlx_new_window((*window()).mlx, (*window()).size_x * 64, 
			(*window()).size_y * 64, "Silver Rush");
	window_load(map, 0, 0);
	mlx_loop((*window()).mlx);
}
