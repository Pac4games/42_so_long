/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:35:20 by paugonca          #+#    #+#             */
/*   Updated: 2023/03/17 19:24:54 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_path(char **tmp, t_pos pos, int collet)
{

}

void	check_path(char **map)
{
	char	**tmp;
	int		p;
	
	p = 0;
	while (map[p])
		p++;
	tmp = malloc(p * sizeof(char *) + 1);
	p = 0;
	while (map[p])
	{
		tmp[p] = ft_strdup(map[p]);
		p++;
	}
	if (!tmp)
		return ;
	find_path(tmp, get_player_pos(map), count_collet(map));
}
