/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:33:05 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/01 14:57:02 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
t_data	*window(void)
{
	t_data	window;

	return (&window);
}
*/

int	main(int ac, char **av)
{
	char	**map;

	map = 0;
	if (ac != 2)
		print_error("Please select one and only one map.");
	map = map_load(av[1]);
	check_map(map);
	free(map);
}
