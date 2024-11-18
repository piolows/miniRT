/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zsimd_cross_product.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:21:59 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 22:59:00 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vect	cross_vect(t_vect *v1, t_vect *v2)
{
	__m256d	vec1;
	__m256d	vec2;
	__m256d	temp1;
	__m256d	temp2;
	t_vect	result;

	vec1 = _mm256_set_pd(0, v1->x, v1->z, v1->y);
	vec2 = _mm256_set_pd(0, v2->y, v2->x, v2->z);
	temp1 = _mm256_mul_pd(vec1, vec2);
	vec1 = _mm256_set_pd(0, v1->y, v1->x, v1->z);
	vec2 = _mm256_set_pd(0, v2->x, v2->z, v2->y);
	temp2 = _mm256_mul_pd(vec1, vec2);
	temp1 = _mm256_sub_pd(temp1, temp2);
	_mm256_storeu_pd((double *)&result, temp1);
	return (result);
}

t_vect3	cross_vect3(t_vect3 *v1, t_vect3 *v2)
{
	t_vect3	result;

	result.x = v1->y * v2->z - v1->z * v2->y;
	result.y = v1->z * v2->x - v1->x * v2->z;
	result.z = v1->x * v2->y - v1->y * v2->x;
	return (result);
}
