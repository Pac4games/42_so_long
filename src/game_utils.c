/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:11:04 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/04 22:28:33 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_move(int key)
{
	if (key == key_up)
		ft_putstr_fd("Moving up\n", 1);
	else if (key == key_down)
		ft_putstr_fd("Moving down\n", 1);
	else if (key == key_left)
		ft_putstr_fd("Moving left\n", 1);
	else if (key == key_right)
		ft_putstr_fd("Moving right\n", 1);
	return (0);
}
