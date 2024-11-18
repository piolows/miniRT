/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:55:56 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/03 22:29:24 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// static int	size_t_len(size_t n)
// {
// 	int	i;

// 	i = 0;
// 	if (n < 0)
// 	{
// 		n *= -1;
// 		i++;
// 	}
// 	while (n > 0)
// 	{
// 		n /= 10;
// 		i++;
// 	}
// 	return (i);
// }

// static char	*size_t_to_char(char *str, size_t n)
// {
// 	int	i;

// 	i = size_t_len(n);
// 	str[i] = '\0';
// 	if (n < 0)
// 	{
// 		*str = '-';
// 		n *= -1;
// 	}
// 	while (n > 0)
// 	{
// 		str[--i] = (n % 10) + 48;
// 		n /= 10;
// 	}
// 	return (str);
// }

// char	*ft_stoa(size_t n)
// {
// 	char	*str;

// 	if (n == 0)
// 		return (ft_strdup("0"));
// 	str = ft_calloc(sizeof(char), (size_t_len(n) + 1));
// 	if (!str)
// 		return (NULL);
// 	return (size_t_to_char(str, n));
// }

// void	save(t_data *data)
// {
// 	FILE	*fp;
// 	char	*filename;
// 	char	*temp;

// 	filename = ft_stoa(get_time());
// 	temp = filename;
// 	filename = ft_strjoin(filename, ".bin");
// 	free(temp);
// 	fp = fopen(filename, "w");
// 	free(filename);
// 	fwrite(data, sizeof(t_data), 1, fp);
// 	fclose(fp);
// }

// void	load(t_data *data)
// {
// 	FILE	*fp;

// 	printf("%s\n", data->av[1]);
// 	fp = fopen(data->av[1], "r");
// 	if (!fp)
// 	{
// 		ft_putendl_fd(RED BOLD"Invalid save file."RESET, 2);
// 		destroy_all(data, 0);
// 	}
// 	fread(data, sizeof(t_data), 1, fp);
// 	fclose(fp);
// }
