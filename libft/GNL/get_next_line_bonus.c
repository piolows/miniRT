/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:33:32 by ppolinta          #+#    #+#             */
/*   Updated: 2023/11/28 15:20:02 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[10240][BUFFER_SIZE + 1u];
	char		*holder;
	int			bytes;

	if (fd < 0)
		return (NULL);
	holder = NULL;
	bytes = 0;
	while (!holder || !gnl_strchr(holder, '\n'))
	{
		if (!*buff[fd])
		{
			bytes = read(fd, buff[fd], BUFFER_SIZE);
			if (bytes == 0)
				return (holder);
			if (bytes < 0 && holder)
				free(holder);
			if (bytes < 0)
				return (NULL);
			buff[fd][bytes] = '\0';
		}
		holder = appendbuff(holder, buff[fd]);
	}
	return (holder);
}
