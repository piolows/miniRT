/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axis_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:19:32 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 14:41:05 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_matrix	orientation_matrix(t_vect axis, double angle)
{
	double		cos_ang;
	double		sin_ang;
	t_matrix	result;

	cos_ang = cos(angle);
	sin_ang = sin(angle);
	result.r1 = create_vect(cos_ang + sqr(axis.x) * (1 - cos_ang),
			axis.x * axis.y * (1 - cos_ang) - axis.z * sin_ang,
			axis.x * axis.z * (1 - cos_ang) - axis.y * sin_ang, 0);
	result.r2 = create_vect(axis.y * axis.x * (1 - cos_ang) - axis.z * sin_ang,
			cos_ang + sqr(axis.y) * (1 - cos_ang),
			axis.y * axis.z * (1 - cos_ang) - axis.x * sin_ang, 0);
	result.r3 = create_vect(axis.z * axis.x * (1 - cos_ang) - axis.y * sin_ang,
			axis.z * axis.y * (1 - cos_ang) - axis.x * sin_ang,
			cos_ang + sqr(axis.z) * (1 - cos_ang), 0);
	result.r4 = create_vect(0, 0, 0, 1);
	return (result);
}

t_matrix	axis_rotation(t_vect orientation)
{
	t_vect		up;
	t_vect		axis;
	double		angle;

	up = create_vect(0, 1, 0, 0);
	axis = cross_vect(&up, &orientation);
	axis = normalise_vect(&axis);
	angle = acos(dot_vect(&up, &orientation));
	return (orientation_matrix(axis, angle));
}
