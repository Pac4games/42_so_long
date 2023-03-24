/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:33:05 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/24 11:37:07 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*window(void)
{
	static t_data	window;

	return (&window);
}

int	main(int ac, char **av)
{
	static char	**map;
	t_list		*cursor;

	map = 0;
	cursor = 0;
	if (ac != 2)
		print_error("please select one and only one map.", 0);
	map = map_load(av[1], cursor);
	check_map(map);
	window_create(map);
}
