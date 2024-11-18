/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:44:18 by ppolinta          #+#    #+#             */
/*   Updated: 2024/10/30 20:25:09 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_shape	create_cylinder(t_vect point, double radius, double min, double max)
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
	result.type = CYLINDER;
	return (result);
}
