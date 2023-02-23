/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:33:05 by paugonca          #+#    #+#             */
/*   Updated: 2023/02/23 12:00:22 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

t_data	*window(void)
{
	static t_data	window;

	return (&window);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "B2T: Silver Rush");
	img.path = "../assets/Luna_front.xpm";
	img.width = 64;
	img.height = 64;
	img.img = mlx_xpm_file_to_image(mlx, img.path, &img.width, &img.height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
