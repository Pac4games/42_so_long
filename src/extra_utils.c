/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:01:19 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/23 16:48:39 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_image	image_make(char *path)
{
	t_image	img;

	img.img = mlx_xpm_file_to_image((*window()).mlx, path, &img.size,
			&img.size);
	return (img);
}

t_sprites	image_set(void)
{
	static t_sprites	spr;
	static int			p;

	if (!p++)
	{
		spr.wall = image_make(WALL);
		spr.floor = image_make(FLOOR);
		spr.door_open = image_make(DOOR_OPEN);
		spr.door_closed = image_make(DOOR_CLOSED);
		spr.player_up = image_make(PLAYER_UP);
		spr.player_down = image_make(PLAYER_DOWN);
		spr.player_left = image_make(PLAYER_LEFT);
		spr.player_right = image_make(PLAYER_RIGHT);
		spr.collectible = image_make(COLLECTIBLE);
	}
	return (spr);
}

void	display_stats(int steps, int hp)
{
	char	*tmp_join;
	char	*tmp_itoa;

	tmp_itoa = ft_itoa(steps);
	tmp_join = ft_strjoin("Steps: ", tmp_itoa);
	print_onscreen(tmp_join, 4, 16);
	free(tmp_itoa);
	free(tmp_join);
	tmp_itoa = ft_itoa(hp);
	tmp_join = ft_strjoin("HP: ", tmp_itoa);
	print_onscreen(tmp_join, 4, 32);
	free(tmp_itoa);
	free(tmp_join);
}
