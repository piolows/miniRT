/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zsimd_dot_product.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:21:10 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 22:59:41 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	dot_vect(t_vect *v1, t_vect *v2)
{
	__m256d	vec1;
	__m256d	vec2;
	__m256d	temp;

	if (!v1 || !v2)
		return (0);
	vec1 = _mm256_loadu_pd((double *)v1);
	vec2 = _mm256_loadu_pd((double *)v2);
	temp = _mm256_mul_pd(vec1, vec2);
	return (_mm256_reduce_add_pd(temp));
}

double	dot_vect3(t_vect3 *v1, t_vect3 *v2)
{
	__m256d	vec1;
	__m256d	vec2;
	__m256d	temp;

	if (!v1 || !v2)
		return (0);
	vec1 = _mm256_set_pd(0, v1->z, v1->y, v1->x);
	vec2 = _mm256_set_pd(0, v2->z, v2->y, v2->x);
	temp = _mm256_mul_pd(vec1, vec2);
	return (_mm256_reduce_add_pd(temp));
}
