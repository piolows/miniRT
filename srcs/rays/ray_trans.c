/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:35:09 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 18:10:08 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vect	reflect(t_vect *lp, t_vect *n)
{
	t_vect	result;

	result = multiply_vect(n, 2 * dot_vect(lp, n));
	result = subtract_vectors(lp, &result);
	return (result);
}

t_ray	translate_ray(t_ray *ray, t_matrix *trans)
{
	t_ray	result;

	result.origin = multiply_matrix_tvect(trans, &ray->origin);
	result.direction = ray->direction;
	return (result);
}

t_ray	scale_ray(t_ray *ray, t_matrix *trans)
{
	t_ray	result;

	result.origin = multiply_matrix_tvect(trans, &ray->origin);
	result.direction = multiply_matrix_tvect(trans, &ray->direction);
	return (result);
}
