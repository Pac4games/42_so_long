/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:09:50 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/06 14:39:32 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

//Assets path definitions
# define PLAYER_DOWN "assets/luka_down.xpm"
# define WALL "assets/wall_front.xpm"
# define FLOOR "assets/floor.xpm"
# define COLLECTIBLE "assets/antidote1.xpm"
# define EXIT "assets/exit.xpm"

typedef struct s_data 
{
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
	int		size_x;
	int		size_y;
	int		img_x;
	int		img_y;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		count;
	char	**map;
	char	*addr;
}				t_data;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

enum e_keys
{
	key_up = 119,
	key_down = 115,
	key_left = 97,
	key_right = 100
};

//Structs
t_data		*window(void);

//Map and check utils
char		**map_load(char *path, t_list *cursor);
int			map_size(char **map, char axis);
void		map_update(char **map, int x, int y);
void		check_map(char **map);

//Game utils
void		window_create(char **map);
void		window_load(char **map, int p, int i);
int			window_update(void);
int			player_move(int key, char **map);

//Print utils
void		print_matrix(char **matrix);
void		print_error(char *msg);
void		print_game_over(char *msg);

#endif
