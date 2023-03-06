/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:22:06 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/06 12:21:59 by paugonca         ###   ########.fr       */
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

void	print_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

void	print_game_over(char *msg)
{
	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	exit(EXIT_SUCCESS);
}
