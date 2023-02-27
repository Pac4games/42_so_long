/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:33:05 by paugonca          #+#    #+#             */
/*   Updated: 2023/02/27 17:34:56 by paugonca         ###   ########.fr       */
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
	int		i = 0;

	map = 0;
	if (ac != 2)
		print_error("Please select one and only one map.\n");
	map = map_load(av[1]);
	while (map[i])
	{
		printf("%s", map[i]);
		free(map[i++]);
	}
	free(map);
}
