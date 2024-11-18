/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zsimd_vect_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:20:44 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 23:14:22 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// Add vectors
t_vect	add_vectors(t_vect *v1, t_vect *v2)
{
	t_vect		result;
	__m256d		vec1;	
	__m256d		vec2;
	__m256d		temp;

	if (!v1 || !v2)
		return (error_vect());
	vec1 = _mm256_loadu_pd((double *)v1);
	vec2 = _mm256_loadu_pd((double *)v2);
	temp = _mm256_add_pd(vec1, vec2);
	_mm256_storeu_pd((double *)&result, temp);
	return (result);
}

t_vect	multiply_vect(t_vect *vect, double multiplier)
{
	t_vect	result;
	__m256d	vec;
	__m256d	temp;

	if (!vect)
		return (error_vect());
	vec = _mm256_loadu_pd((double *)vect);
	temp = _mm256_set1_pd(multiplier);
	vec = _mm256_mul_pd(vec, temp);
	_mm256_storeu_pd((double *)&result, vec);
	return (result);
}

// Subtract vectors (double precision)
t_vect	subtract_vectors(t_vect *v1, t_vect *v2)
{
	t_vect		result;
	__m256d		vec1;
	__m256d		vec2;
	__m256d		temp;

	if (!v1 || !v2)
		return (error_vect());
	vec1 = _mm256_loadu_pd((double *)v1);
	vec2 = _mm256_loadu_pd((double *)v2);
	temp = _mm256_sub_pd(vec1, vec2);
	_mm256_storeu_pd((double *)&result, temp);
	return (result);
}

int	compare_vects(t_vect *v1, t_vect *v2)
{
	if ((fabs(v1->x - v2->x) < EPSILON)
		&& (fabs(v1->y - v2->y) < EPSILON)
		&& (fabs(v1->z - v2->z) < EPSILON))
		return (0);
	return (1);
}
