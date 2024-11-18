/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:47:20 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 22:02:32 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static inline void	populate_lighting(t_world *w, t_comp *comp,
	t_lighting *l, uint8_t i)
{
	l->shape = comp->shape;
	l->mat = comp->shape->mat;
	l->light = &w->light[i];
	l->eyev = comp->eyev;
	l->normalv = comp->normalv;
	if (w->settings.shadows)
		l->in_shadow = is_shadowed(w, &w->light[i], &comp->over_pos);
	if (w->settings.shadows && l->in_shadow)
		l->point = comp->over_pos;
	else
	{
		l->in_shadow = 0;
		l->point = comp->position;
	}
}

t_rgb	shade_hit(t_world *world, t_comp *comp, char recurse)
{
	t_rgb		result;
	t_rgb		temp;
	uint8_t		i;
	t_lighting	l;

	i = 1;
	if (world->settings.flashlight)
		i = 0;
	result = get_rgb(0x00000000);
	while (i < world->light_srcs)
	{
		populate_lighting(world, comp, &l, i);
		temp = lighting(&l);
		result = add_colours(&result, &temp);
		i++;
	}
	if (world->settings.reflections)
	{
		temp = reflected_colour(world, comp, recurse);
		result = add_colours(&result, &temp);
	}
	return (result);
}

t_rgb	colour_at(t_world *world, t_ray *ray, char recurse)
{
	t_inter		x[X_MAX];
	t_comp		comp;
	t_rgb		colour[2];
	uint16_t	x_count;
	t_inter		*hit;

	x_count = 0;
	populate_inter(world, ray, x, &x_count);
	if (!x_count)
		return (get_rgb(0x00000000));
	hit = get_hit(x, &x_count);
	if (!hit)
		return (get_rgb(0x00000000));
	if (world->settings.superfast)
		return (hit->obj->mat.colour);
	comp = computations(ray, get_hit(x, &x_count));
	colour[0] = shade_hit(world, &comp, recurse);
	colour[1] = hadamard_product(&world->ambient_light,
			&comp.shape->mat.colour);
	colour[0] = add_colours(&colour[0], &colour[1]);
	return (colour[0]);
}
