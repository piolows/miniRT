/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:34:23 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/17 00:50:51 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_rgb	*uv_pattern_at(t_pattern *pattern, double u, double v)
{
	double	u2;
	double	v2;

	u2 = floor(u * pattern->width);
	v2 = floor(v * pattern->height);
	if ((int)roundf(u2 + v2) % 2)
		return (&pattern->b);
	else
		return (&pattern->a);
}

t_pattern	uv_checkers(int width, int height, t_rgb a, t_rgb b)
{
	t_pattern	result;

	result.type = CHECKER;
	result.a = a;
	result.b = b;
	result.width = width;
	result.height = height;
	return (result);
}

t_rgb	*checker_at_object(t_pattern *pattern, t_shape *shape, t_vect *point)
{
	t_vect	obj_point;

	obj_point = multiply_matrix_tvect(&shape->inv, point);
	return (checker_at(pattern, obj_point, shape->type));
}

t_rgb	*checker_at(t_pattern *pattern, t_vect point, int type)
{
	double	uv[2];

	uv[0] = 0;
	uv[1] = 0;
	if (type == SPHERE)
		spherical_map(point, uv);
	else if (type == PLANE)
		planar_map(point, uv);
	return (uv_pattern_at(pattern, uv[0], uv[1]));
}
