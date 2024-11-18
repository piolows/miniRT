/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:43:14 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/17 00:27:42 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	rt_atod(char *str, t_data *data)
{
	double	nbr;
	double	sign;
	double	decimal;
	size_t	i;

	i = 0;
	nbr = 0;
	decimal = 10;
	sign = 1 - (2 * (str[i] == '-'));
	i += (str[i] == '-' || str[i] == '+');
	while (str[i] && ft_isdigit(str[i]))
	{
		if ((nbr > __DBL_MAX__ / 10) || ((nbr == __DBL_MAX__ / 10)
				&& (str[i] - '0') > __DBL_MAX__ - nbr * 10))
			rt_error(WR_FORMAT_DBL, data);
		nbr = nbr * 10 + (str[i++] - '0');
	}
	i += (str[i] == '.');
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr += (str[i++] - '0') / (decimal);
		decimal *= 10;
	}
	return (nbr * sign);
}

void	count_commas(char *vect, t_data *data)
{
	int	comma_cnt;
	int	i;

	i = 0;
	comma_cnt = 0;
	while (vect[i])
		if (vect[i++] == ',')
			comma_cnt++;
	if (comma_cnt > 2)
		rt_error(WR_FORMAT_VECT, data);
}

t_vect	get_vect(char *vect, int type, t_data *data)
{
	char	**split_args;
	t_vect	result;
	size_t	i;

	i = 0;
	count_commas(vect, data);
	split_args = ft_split(vect, ',');
	if (!split_args || array_len(split_args) != 3)
		rt_error(WR_FORMAT_VECT, data);
	while (split_args[i])
	{
		if ((type == DBL && !is_double(split_args[i]))
			|| (type == INT && !is_int(split_args[i])))
			rt_error(WR_FORMAT_VECT, data);
		i++;
	}
	if (type == DBL)
		result = create_vect(rt_atod(split_args[0], data),
				rt_atod(split_args[1], data), rt_atod(split_args[2], data), 0);
	else
		result = create_vect(ft_atoi(split_args[0]), ft_atoi(split_args[1]),
				ft_atoi(split_args[2]), 0);
	freearray(split_args);
	return (result);
}
