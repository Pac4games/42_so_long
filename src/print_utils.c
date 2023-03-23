/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:22:06 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/23 17:46:40 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_matrix(char **matrix)
{
	int	p;

	p = 0;
	while (matrix[p])
		ft_putstr_fd(matrix[p++], 1);
}

void	print_error(char *msg, char **map)
{
	int	p;

	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	p = 0;
	if (map)
	{
		while (map[p])
			free(map[p++]);
		free(map);
	}
	exit(EXIT_FAILURE);
}

void	print_game_over(char *msg, char **map)
{
	int	p;

	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	mlx_clear_window((*window()).mlx, (*window()).win);
	window_destroy_sprites();
	mlx_destroy_window((*window()).mlx, (*window()).win);
	mlx_destroy_display((*window()).mlx);
	free((*window()).mlx);
	p = 0;
	while (map[p])
		free(map[p++]);
	free(map);
	exit(EXIT_SUCCESS);
}

int	print_game_closed(char **map)
{
	print_game_over("Game closed.", map);
	return (0);
}

void	print_onscreen(char *msg, int x, int y)
{
	mlx_string_put((*window()).mlx, (*window()).win, x, y, 0, msg);
}
