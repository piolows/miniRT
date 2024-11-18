/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:44:50 by ppolinta          #+#    #+#             */
/*   Updated: 2024/10/20 21:03:02 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	print_ray(t_ray ray)
{
	print_vect(ray.origin, "Ray origin\t");
	print_vect(ray.direction, "Ray direction\t");
}

// Returns the point the ray would end up at after
// travelling from its origin  by its direction for t seconds wow
t_vect	position(t_ray *ray, double t)
{
	t_vect	result;

	result.x = ray->origin.x + ray->direction.x * t;
	result.y = ray->origin.y + ray->direction.y * t;
	result.z = ray->origin.z + ray->direction.z * t;
	result.w = 1;
	return (result);
}

t_ray	create_ray(t_vect *vector, t_vect *point)
{
	t_ray	result;

	result.direction = *vector;
	result.origin = *point;
	return (result);
}

t_ray	*new_ray(t_vect *vector, t_vect *point)
{
	t_ray	*result;

	result = ft_calloc(1, sizeof(t_ray));
	if (!result)
		return (NULL);
	*result = create_ray(vector, point);
	return (result);
}
