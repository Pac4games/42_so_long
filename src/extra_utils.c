/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:01:19 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/18 15:17:34 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy(void *img)
{
	mlx_destroy_image((*window()).mlx, img);
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
