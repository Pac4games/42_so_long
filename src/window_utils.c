/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:35:03 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/01 16:24:08 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_create(char **map)
{
	(*window()).size_x = map_size(map, 'x');
	(*window()).size_y = map_size(map, 'y');
	printf("Window width: %d\n", (*window()).size_x);
	printf("Window height: %d\n", (*window()).size_y);
	(*window()).mlx = mlx_init();
	mlx_new_window((*window()).mlx, (*window()).size_x * 64, (*window()).size_y * 64, "Silver Rush");
	mlx_loop((*window()).mlx);
}
