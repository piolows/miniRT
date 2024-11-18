/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:05:56 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/07 15:41:55 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_shape	create_sphere(t_vect point, double radius)
{
	t_shape		result;

	default_shape_values(&result);
	result.radius = radius;
	if (point.x || point.y || point.z)
		transform(&result, translation(point.x, point.y, point.z), TRANSL);
	if (radius != 1)
		transform(&result, scaling(radius, radius, radius), SCALE);
	result.type = SPHERE;
	return (result);
}

// t_sphere	*new_sphere(t_vect *point, double radius)
// {
// 	t_sphere	*result;

// 	result = ft_calloc(1, sizeof(t_sphere));
// 	if (!result)
// 		return (NULL);
// 	*result = create_sphere(point, radius);
// 	return (result);
// }
