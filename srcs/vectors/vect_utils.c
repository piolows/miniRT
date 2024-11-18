/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:59:17 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/17 01:17:50 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vect	normalise_vect(t_vect *vect)
{
	double	length;
	t_vect	result;

	length = vect_length(vect);
	if (!length)
		return (error_vect());
	result.x = vect->x / length;
	result.y = vect->y / length;
	result.z = vect->z / length;
	result.w = 0;
	return (result);
}

double	vect_lengthsq(t_vect *vect)
{
	if (!vect)
		return (0);
	return (vect->x * vect->x + vect->y * vect->y + vect->z * vect->z);
}

double	vect_length(t_vect *vect)
{
	return (sqrt(vect_lengthsq(vect)));
}
