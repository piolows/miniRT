/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:24:09 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/17 00:30:35 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	*free_array(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return (NULL);
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

int	word_count(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
		{
			while (*str && *str != ' ' && *str != '\t')
				str++;
			count++;
		}
		else
			str++;
	}
	return (count);
}

char	*get_word(char *str)
{
	int		i;
	int		length;
	char	*word;

	length = 0;
	while (str[length] && str[length] != ' ' && str[length] != '\t')
		length++;
	word = malloc(sizeof(char) * (length + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && i < length)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**rt_split(char *str)
{
	int		i;
	int		j;
	int		wrdcnt;
	char	**split_str;

	if (!str)
		return (NULL);
	wrdcnt = word_count(str);
	split_str = malloc(sizeof(char *) * (wrdcnt + 1));
	if (!split_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j < wrdcnt)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		split_str[j] = get_word(&str[i]);
		if (!split_str[j])
			return (free_array(split_str));
		i += ft_strlen(split_str[j++]);
	}
	split_str[j] = NULL;
	return (split_str);
}
