/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:35:03 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/16 15:05:33 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	window_set_tile(char tile, char *player, char *exit, int x, int y)
{
	if (tile == '1')
		(*window()).img = mlx_xpm_file_to_image((*window()).mlx, WALL,
				&(*window()).img_x, &(*window()).img_y);
	else if (tile == '0')
		(*window()).img = mlx_xpm_file_to_image((*window()).mlx, FLOOR,
				&(*window()).img_x, &(*window()).img_y);
	else if (tile == 'P')
		(*window()).img = mlx_xpm_file_to_image((*window()).mlx,
				player, &(*window()).img_x, &(*window()).img_y);
	else if (tile == 'C')
		(*window()).img = mlx_xpm_file_to_image((*window()).mlx,
				COLLECTIBLE, &(*window()).img_x, &(*window()).img_y);
	else if (tile == 'E')
		(*window()).img = mlx_xpm_file_to_image((*window()).mlx,
				exit, &(*window()).img_x, &(*window()).img_y);
	else if (tile != '\n')
		print_error("invalid object detected in map.");
	mlx_put_image_to_window((*window()).mlx, (*window()).win, (*window()).img,
		x * 64, y * 64);
}

void	window_load(char **map, char *player, int p, int i)
{
	static char *exit;

	exit = get_exit_sprite(map);
	while (map[p])
	{
		i = 0;
		while (map[p][i])
		{
			window_set_tile(map[p][i], player, exit, i, p);
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
	int	x;
	int	y;

	destroy(mlx_xpm_file_to_image((*window()).mlx, PLAYER_UP, &x, &y));
	destroy(mlx_xpm_file_to_image((*window()).mlx, PLAYER_DOWN, &x, &y));
	destroy(mlx_xpm_file_to_image((*window()).mlx, PLAYER_LEFT, &x, &y));
	destroy(mlx_xpm_file_to_image((*window()).mlx, PLAYER_RIGHT, &x, &y));
	destroy(mlx_xpm_file_to_image((*window()).mlx, FLOOR, &x, &y));
	destroy(mlx_xpm_file_to_image((*window()).mlx, WALL, &x, &y));
	destroy(mlx_xpm_file_to_image((*window()).mlx, EXIT_OPEN, &x, &y));
	destroy(mlx_xpm_file_to_image((*window()).mlx, EXIT_CLOSED, &x, &y));
	destroy(mlx_xpm_file_to_image((*window()).mlx, COLLECTIBLE, &x, &y));
}

void	window_create(char **map)
{
	(*window()).size_x = map_size(map, 'x');
	(*window()).size_y = map_size(map, 'y');
	(*window()).mlx = mlx_init();
	(*window()).win = mlx_new_window((*window()).mlx, (*window()).size_x * 64,
			(*window()).size_y * 64, "Silver Rush");
	window_load(map, PLAYER_DOWN, 0, 0);
	print_onscreen("Steps: 0", 4, 16);
	print_onscreen("HP: 5", 4, 32);
	mlx_key_hook((*window()).win, player_move, map);
	mlx_hook((*window()).win, 17, 0, print_game_over, "Game closed.");
	mlx_loop_hook((*window()).win, window_update, 0);
	mlx_loop((*window()).mlx);
}
