/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:40:26 by paugonca          #+#    #+#             */
/*   Updated: 2023/02/24 21:21:56 by paugonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*res;
	int			p;

	p = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (buf[p])
			buf[p++] = 0;
		return (NULL);
	}
	res = NULL;
	while (buf[0] || read(fd, buf, BUFFER_SIZE) > 0)
	{
		res = gnl_strjoin(res, buf);
		if (clean_buf(buf))
			break ;
	}
	return (res);
}
