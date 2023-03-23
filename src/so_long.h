/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:09:50 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/23 17:46:28 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx_linux/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

//Defining sprites 
# define PLAYER_UP "assets/luka_up.xpm"
# define PLAYER_DOWN "assets/luka_down.xpm"
# define PLAYER_LEFT "assets/luka_left.xpm"
# define PLAYER_RIGHT "assets/luka_right.xpm"
# define WALL "assets/wall_front.xpm"
# define FLOOR "assets/floor.xpm"
# define COLLECTIBLE "assets/antidote.xpm"
# define DOOR_CLOSED "assets/door_closed.xpm"
# define DOOR_OPEN "assets/door_open.xpm"

//Defining input
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_ESC 65307

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;
	int		size_x;
	int		size_y;
	int		img_x;
	int		img_y;
}				t_data;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size;
}				t_image;

typedef struct s_sprites
{
	t_image	player_up;
	t_image	player_down;
	t_image	player_left;
	t_image	player_right;
	t_image	wall;
	t_image	floor;
	t_image	collectible;
	t_image	door_closed;
	t_image	door_open;
}				t_sprites;

//Window struct
t_data		*window(void);

//Map and check utils
char		**map_load(char *path, t_list *cursor);
int			map_size(char **map, char axis);
void		map_update(char **map, int key, int x, int y);
void		check_path(char **map, int x, int y);
void		check_map(char **map);

//Game utils
void		window_create(char **map);
void		window_load(char **map, int key, int p, int i);
int			window_update(void);
void		window_destroy_sprites(void);
t_sprites	image_set(void);
void		display_stats(int steps, int hp);
t_pos		get_player_pos(char **map);
int			player_move(int key, char **map);
void		*get_player_sprite(int key);
void		*get_door_sprite(char **map);

//Print utils
void		print_matrix(char **matrix);
void		print_error(char *msg, char **map);
void		print_game_over(char *msg, char **map);
int			print_game_closed(char **map);
void		print_onscreen(char *msg, int x, int y);

#endif
