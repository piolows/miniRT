/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:17:21 by ppolinta          #+#    #+#             */
/*   Updated: 2024/10/22 18:37:18 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_rgb	reflected_colour(t_world *w, t_comp *comp, char recurse)
{
	t_ray	ray;
	t_rgb	colour;

	if (recurse <= 0 || comp->shape->mat.reflective < EPSILON)
		return (get_rgb(0x00000000));
	ray.origin = comp->over_pos;
	ray.direction = comp->reflectv;
	colour = colour_at(w, &ray, recurse - 1);
	return (multiply_colours(&colour, comp->shape->mat.reflective));
}
