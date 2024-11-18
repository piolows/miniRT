/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:29:49 by agodeanu          #+#    #+#             */
/*   Updated: 2024/10/30 20:25:18 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_shape	create_plane(t_vect point, double rot_x, double rot_y, double rot_z)
{
	t_shape		plane;

	plane.type = PLANE;
	default_shape_values(&plane);
	if (point.x || point.y || point.z)
		transform(&plane, translation(point.x, point.y, point.z), TRANSL);
	if (rot_x)
		transform(&plane, rotation_x(rot_x), ROT);
	if (rot_y)
		transform(&plane, rotation_y(rot_y), ROT);
	if (rot_z)
		transform(&plane, rotation_z(rot_z), ROT);
	return (plane);
}

// t_plane	*new_plane(t_vect point, double rot_x, double rot_y, double rot_z)
// {
// 	t_plane	*result;

// 	result = ft_calloc(sizeof(t_plane), 1);
// 	if (!result)
// 		return (NULL);
// 	*result = create_plane(point, rot_x, rot_y, rot_z);
// 	return (result);
// }
