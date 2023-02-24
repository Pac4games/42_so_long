/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:33:05 by paugonca          #+#    #+#             */
/*   Updated: 2023/02/24 15:47:49 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		width;
	int		height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Silver Rush");
	img = mlx_xpm_file_to_image(mlx, PLAYER_FRONT, &width, &height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
}
