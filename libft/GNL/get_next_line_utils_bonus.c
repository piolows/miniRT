/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:12:07 by ppolinta          #+#    #+#             */
/*   Updated: 2023/11/28 15:22:34 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*gnl_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cs;
	unsigned char	*cd;

	if (!dst && !src)
		return (NULL);
	cs = (unsigned char *)src;
	cd = (unsigned char *)dst;
	if (dst > src)
	{
		while (len-- > 0)
			cd[len] = cs[len];
	}
	else
		while (len-- > 0)
			*cd++ = *cs++;
	return (dst);
}

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*gnl_strchr(const char *s, int c)
{
	int	i;

	if ((unsigned char)c == '\0')
		return ((char *)&s[gnl_strlen(s)]);
	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

char	*appendbuff(char *str, char *buff)
{
	char	*apd;

	apd = gnl_strjoin(str, buff);
	if (str)
		free(str);
	if (gnl_strchr(buff, '\n'))
		gnl_memmove(buff, gnl_strchr(buff, '\n') + 1,
			gnl_strlen(gnl_strchr(buff, '\n') + 1) + 1);
	else
		*buff = '\0';
	return (apd);
}
