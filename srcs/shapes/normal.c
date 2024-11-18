/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 01:12:43 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 22:17:00 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vect	normal_cube(t_shape *c, t_vect *point)
{
	t_vect		obj_normal;
	t_vect		obj_point;
	t_vect		world_normal;

	obj_point = multiply_matrix_tvect(&c->inv, point);
	if (fabs(obj_point.x) > fabs(obj_point.y)
		&& fabs(obj_point.x) > fabs(obj_point.z))
		obj_normal = create_vect(obj_point.x, 0, 0, 0);
	else if (fabs(obj_point.y) > fabs(obj_point.x)
		&& fabs(obj_point.y) > fabs(obj_point.z))
		obj_normal = create_vect(0, obj_point.y, 0, 0);
	else
		obj_normal = create_vect(0, 0, obj_point.z, 0);
	world_normal = multiply_matrix_tvect(&c->tp, &obj_normal);
	world_normal.w = 0;
	return (normalise_vect(&world_normal));
}

t_vect	normal_cone(t_shape *c, t_vect *point)
{
	t_vect		obj_normal;
	t_vect		obj_point;
	t_vect		world_normal;
	double		dist;

	obj_point = multiply_matrix_tvect(&c->inv, point);
	dist = sqr(obj_point.x) + sqr(obj_point.z);
	if ((dist - sqr(c->max)) < OFFSET && obj_point.y >= c->max - OFFSET)
		obj_normal = create_vect(0, 1, 0, 0);
	else if ((dist - sqr(c->min)) < OFFSET && obj_point.y <= c->min + OFFSET)
		obj_normal = create_vect(0, -1, 0, 0);
	else
	{
		obj_normal = subtract_vectors(&obj_point, &c->origin);
		obj_normal.y = sqrt(sqr(obj_point.x) + sqr(obj_point.z));
		if (obj_point.y > 0)
			obj_normal.y *= -1;
	}
	world_normal = multiply_matrix_tvect(&c->tp, &obj_normal);
	world_normal.w = 0;
	return (normalise_vect(&world_normal));
}

t_vect	normal_cylinder(t_shape *c, t_vect *point)
{
	t_vect		obj_normal;
	t_vect		obj_point;
	t_vect		world_normal;
	double		dist;

	obj_point = multiply_matrix_tvect(&c->inv, point);
	dist = sqr(obj_point.x) + sqr(obj_point.z);
	if (dist - 1 < OFFSET && obj_point.y >= c->max - OFFSET)
		obj_normal = create_vect(0, 1, 0, 0);
	else if (dist - 1 < OFFSET && obj_point.y <= c->min + OFFSET)
		obj_normal = create_vect(0, -1, 0, 0);
	else
	{
		obj_normal = subtract_vectors(&obj_point, &c->origin);
		obj_normal.y = 0;
	}
	world_normal = multiply_matrix_tvect(&c->tp, &obj_normal);
	world_normal.w = 0;
	return (normalise_vect(&world_normal));
}

t_vect	normal_plane(t_shape *p, t_vect *point)
{
	t_vect		world_normal;

	(void)point;
	world_normal = multiply_matrix_tvect(&p->tp, &p->normal);
	world_normal.w = 0;
	return (normalise_vect(&world_normal));
}

t_vect	normal_sphere(t_shape *s, t_vect *point)
{
	t_vect		obj_normal;
	t_vect		obj_point;
	t_vect		world_normal;

	obj_point = multiply_matrix_tvect(&s->inv, point);
	obj_normal = subtract_vectors(&obj_point, &s->origin);
	world_normal = multiply_matrix_tvect(&s->tp, &obj_normal);
	world_normal.w = 0;
	return (normalise_vect(&world_normal));
}
