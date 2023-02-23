/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:09:50 by paugonca          #+#    #+#             */
/*   Updated: 2023/02/20 19:59:37 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	void	*player;
	void	*wall;
	void	*collectible;
	void	*floor;
	void	*exit;
	void	*enemy;
	int		x;
	int		y;
	int		*size_x;
	int		*size_y;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		count;
	char	**map;
	char	*addr;
}				t_data;

#endif
