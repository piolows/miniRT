/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:46:33 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 22:31:50 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	sqr(double nbr)
{
	return (nbr * nbr);
}

int	compare_double(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (0);
	return (1);
}

int	odd_even(int nbr)
{
	if (nbr % 2 == 0)
		return (1);
	return (-1);
}

double	get_min(double a, double b, double c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

double	get_max(double a, double b, double c)
{
	if (a >= b && a >= c)
		return (a);
	if (b >= a && b >= c)
		return (b);
	return (c);
}
