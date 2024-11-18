/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:38:02 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 22:17:33 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_inter	*get_hit(t_inter *inter, uint16_t *x_count)
{
	uint16_t	i;
	double		hit_t;
	t_inter		*temp_x;

	i = 0;
	hit_t = T_MAX;
	temp_x = NULL;
	while (i < *x_count)
	{
		if (inter[i].t > 0 && inter[i].t < hit_t + EPSILON)
		{
			hit_t = inter[i].t;
			temp_x = &inter[i];
		}
		i++;
	}
	return (temp_x);
}

void	intersect(t_shape *shape, t_ray *ray, t_inter *inter, uint16_t *x)
{
	if (shape->type == SPHERE)
		intersect_sphere(inter, shape, ray, x);
	else if (shape->type == PLANE)
		intersect_plane(inter, shape, ray, x);
	else if (shape->type == CYLINDER)
		intersect_cylinder(inter, shape, ray, x);
	else if (shape->type == CONE)
		intersect_cone(inter, shape, ray, x);
	else if (shape->type == CUBE)
		intersect_cube(inter, shape, ray, x);
}

void	populate_inter(t_world *w, t_ray *ray, t_inter *x, uint16_t *x_count)
{
	uint16_t	i;

	i = 0;
	while (i < w->nbr_shapes)
		intersect(&w->shapes[i++], ray, x, x_count);
}

t_vect	normal_calc(t_shape *shape, t_vect *point)
{
	t_vect	result;

	result = create_vect(0, 0, 0, 0);
	if (shape->type == SPHERE)
		result = normal_sphere(shape, point);
	else if (shape->type == PLANE)
		result = normal_plane(shape, point);
	else if (shape->type == CYLINDER)
		result = normal_cylinder(shape, point);
	else if (shape->type == CONE)
		result = normal_cone(shape, point);
	else if (shape->type == CUBE)
		result = normal_cube(shape, point);
	return (result);
}

t_comp	computations(t_ray *ray, t_inter *inter)
{
	t_comp	result;

	result.t = inter->t;
	result.shape = inter->obj;
	result.position = position(ray, result.t);
	result.eyev = multiply_vect(&ray->direction, -1);
	result.eyev = normalise_vect(&result.eyev);
	result.normalv = normal_calc(result.shape, &result.position);
	if (dot_vect(&result.normalv, &result.eyev) < 0)
	{
		result.normalv = multiply_vect(&result.normalv, -1);
		result.inside = 1;
	}
	else
		result.inside = 0;
	result.reflectv = reflect(&ray->direction, &result.normalv);
	result.reflectv = normalise_vect(&result.reflectv);
	result.over_pos = multiply_vect(&result.normalv, OFFSET);
	result.over_pos = add_vectors(&result.position, &result.over_pos);
	return (result);
}
