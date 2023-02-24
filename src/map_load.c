/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:49:40 by paugonca          #+#    #+#             */
/*   Updated: 2023/02/24 18:26:56 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_load(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Failed to read map.\n");
}
