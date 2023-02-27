/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:44:26 by paugonca          #+#    #+#             */
/*   Updated: 2023/02/27 17:43:49 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Tweaked version for this project
void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}
