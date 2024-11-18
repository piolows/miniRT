/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:27:14 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/17 01:19:22 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

char	is_whitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	is_double(char *nbr)
{
	size_t	i;
	char	decimal;

	i = 0;
	decimal = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	if (!nbr[i])
		return (0);
	while (nbr[i] && (ft_isdigit(nbr[i]) || nbr[i] == '.'))
	{
		if (nbr[i] == '.' && decimal == 1)
			return (0);
		if (nbr[i] == '.')
			decimal = 1;
		i++;
	}
	if (!nbr[i] && nbr[i - 1] == '.')
		return (0);
	if (!nbr[i])
		return (1);
	return (0);
}

int	is_int(char *nbr)
{
	size_t	i;

	i = 0;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	if (!nbr[i])
		return (0);
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_normalised(t_vect *vect, t_data *data)
{
	t_vect	norm;

	norm = normalise_vect(vect);
	if (norm.w == -1)
		rt_error(WR_FORMAT_VECT, data);
	if (!compare_vects(vect, &norm))
		return (1);
	return (0);
}
