/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:53:07 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 22:12:13 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_light	create_point_light(t_vect pos, t_rgb intensity)
{
	t_light	result;

	result.point = pos;
	result.intensity = intensity;
	return (result);
}

static inline void	lighting_ext(t_lighting *l)
{
	if (l->dot < 0)
	{
		l->diffuse = get_rgb(0x00000000);
		l->specular = get_rgb(0x00000000);
	}
	else
	{
		l->diffuse = multiply_colours(&l->effective_colour,
				l->mat.diffuse * l->dot);
		l->dot = dot_vect(&l->reflectv, &l->eyev);
		if (l->dot <= 0)
			l->specular = get_rgb(0x00000000);
		else
		{
			l->factor = pow(l->dot, l->mat.shininess);
			l->specular = multiply_colours(&l->light->intensity,
					l->factor * l->mat.specular);
		}
	}
}

t_rgb	lighting(t_lighting *l)
{
	if (l->mat.pattern.type == SOLID)
		l->effective_colour = hadamard_product(&l->mat.colour,
				&l->light->intensity);
	else if (l->mat.pattern.type == CHECKER)
		l->effective_colour = hadamard_product(checker_at_object
				(&l->mat.pattern, l->shape, &l->point), &l->light->intensity);
	l->ambient = multiply_colours(&l->effective_colour, l->mat.ambient);
	if (l->in_shadow)
		return (l->ambient);
	l->lightv = subtract_vectors(&l->light->point, &l->point);
	l->lightv = normalise_vect(&l->lightv);
	l->lightv = multiply_vect(&l->lightv, -1);
	l->reflectv = reflect(&l->lightv, &l->normalv);
	l->lightv = multiply_vect(&l->lightv, -1);
	l->dot = dot_vect(&l->lightv, &l->normalv);
	lighting_ext(l);
	l->result = add_colours(&l->ambient, &l->diffuse);
	l->result = add_colours(&l->result, &l->specular);
	return (l->result);
}

char	is_shadowed(t_world *w, t_light *l, t_vect *p)
{
	t_vect		v;
	t_ray		ray_from_p;
	t_inter		x[X_MAX];
	uint16_t	x_count;
	t_inter		*hit;

	x_count = 0;
	v = subtract_vectors(&l->point, p);
	ray_from_p.direction = normalise_vect(&v);
	ray_from_p.origin = *p;
	populate_inter(w, &ray_from_p, x, &x_count);
	hit = get_hit(x, &x_count);
	if (hit && hit->t < vect_length(&v) - OFFSET)
		return (1);
	else
		return (0);
}
