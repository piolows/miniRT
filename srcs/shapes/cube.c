/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:22:27 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/02 16:02:12 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_shape	create_cube(t_vect point, double radius)
{
	t_shape		result;

	default_shape_values(&result);
	result.radius = radius;
	if (point.x || point.y || point.z)
		transform(&result, translation(point.x, point.y, point.z), TRANSL);
	if (radius != 1)
		transform(&result, scaling(radius, radius, radius), SCALE);
	result.type = CUBE;
	return (result);
}
