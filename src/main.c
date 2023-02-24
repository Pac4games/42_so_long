/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:33:05 by paugonca          #+#    #+#             */
/*   Updated: 2023/02/24 16:45:08 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

t_data	*window(void)
{
	t_data	window;

	return (&window);
}

int	main(int ac, char **av)
{
	char	**map;

	map = 0;
	if (av != 2)
	{
		ft_putstr("Please select one and only one map", 2);
		return (0);
	}
	else
		map = map_load(av[1]);
	create_window(map);
}
