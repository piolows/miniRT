/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:19:45 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 15:05:29 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vect	add_vectors(t_vect *v1, t_vect *v2)
{
	t_vect	result;

	if (!v1 || !v2)
		return (error_vect());
	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	result.w = v1->w + v2->w;
	return (result);
}

t_vect	subtract_vectors(t_vect *v1, t_vect *v2)
{
	t_vect	result;

	if (!v1 || !v2)
		return (error_vect());
	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	result.w = v1->w - v2->w;
	return (result);
}

t_vect	multiply_vect(t_vect *vect, double multiplier)
{
	t_vect	result;

	if (!vect)
		return (error_vect());
	result.x = vect->x * multiplier;
	result.y = vect->y * multiplier;
	result.z = vect->z * multiplier;
	result.w = vect->w * multiplier;
	return (result);
}

t_vect	divide_vect(t_vect *vect, double divisor)
{
	t_vect	result;

	if (!vect)
		return (error_vect());
	result.x = vect->x / divisor;
	result.y = vect->y / divisor;
	result.z = vect->z / divisor;
	result.w = vect->w / divisor;
	return (result);
}

int	compare_vects(t_vect *v1, t_vect *v2)
{
	if ((fabs(v1->x - v2->x) < EPSILON)
		&& (fabs(v1->y - v2->y) < EPSILON)
		&& (fabs(v1->z - v2->z) < EPSILON))
		return (0);
	return (1);
}
