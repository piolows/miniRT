/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:13:11 by ppolinta          #+#    #+#             */
/*   Updated: 2024/10/30 20:25:05 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_shape	create_cone(t_vect point, double radius, double min, double max)
{
	t_shape		result;

	default_shape_values(&result);
	result.radius = radius;
	if (point.x || point.y || point.z)
		transform(&result, translation(point.x, point.y, point.z), TRANSL);
	if (radius != 1)
		transform(&result, scaling(radius, 1, radius), SCALE);
	result.min = min;
	result.max = max;
	result.type = CONE;
	return (result);
}
