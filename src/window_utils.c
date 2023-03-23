/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:35:03 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/23 17:46:21 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	window_set_tile(char **map, int key, int x, int y)
{
	if (map[y][x] == '1')
		mlx_put_image_to_window((*window()).mlx, (*window()).win,
			image_set().wall.img, x * 64, y * 64);
	else if (map[y][x] == '0')
		mlx_put_image_to_window((*window()).mlx, (*window()).win,
			image_set().floor.img, x * 64, y * 64);
	else if (map[y][x] == 'P')
		mlx_put_image_to_window((*window()).mlx, (*window()).win,
			get_player_sprite(key), x * 64, y * 64);
	else if (map[y][x] == 'C')
		mlx_put_image_to_window((*window()).mlx, (*window()).win,
			image_set().collectible.img, x * 64, y * 64);
	else if (map[y][x] == 'E')
		mlx_put_image_to_window((*window()).mlx, (*window()).win,
			get_door_sprite(map), x * 64, y * 64);
	else if (map[y][x] != '\n')
		print_error("invalid object detected in map.", map);
}

void	window_load(char **map, int key, int p, int i)
{
	while (map[p])
	{
		i = 0;
		while (map[p][i])
		{
			window_set_tile(map, key, i, p);
			i++;
		}
		p++;
	}
}

int	window_update(void)
{
	mlx_clear_window((*window()).mlx, (*window()).win);
	return (0);
}

void	window_destroy_sprites(void)
{
	mlx_destroy_image((*window()).mlx, image_set().door_closed.img);
	mlx_destroy_image((*window()).mlx, image_set().door_open.img);
	mlx_destroy_image((*window()).mlx, image_set().player_up.img);
	mlx_destroy_image((*window()).mlx, image_set().player_down.img);
	mlx_destroy_image((*window()).mlx, image_set().player_left.img);
	mlx_destroy_image((*window()).mlx, image_set().player_right.img);
	mlx_destroy_image((*window()).mlx, image_set().floor.img);
	mlx_destroy_image((*window()).mlx, image_set().wall.img);
	mlx_destroy_image((*window()).mlx, image_set().collectible.img);
}

void	window_create(char **map)
{
	(*window()).size_x = map_size(map, 'x');
	(*window()).size_y = map_size(map, 'y');
	(*window()).mlx = mlx_init();
	(*window()).win = mlx_new_window((*window()).mlx, (*window()).size_x * 64,
			(*window()).size_y * 64, "Silver Rush");
	window_load(map, KEY_DOWN, 0, 0);
	print_onscreen("Steps: 0", 4, 16);
	print_onscreen("HP: 5", 4, 32);
	mlx_key_hook((*window()).win, player_move, map);
	mlx_hook((*window()).win, 17, 0, print_game_closed, map);
	mlx_loop_hook((*window()).win, window_update, 0);
	mlx_loop((*window()).mlx);
}
