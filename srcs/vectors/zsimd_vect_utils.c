/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zsimd_vect_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:17:04 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/17 01:12:58 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vect	normalise_vect(t_vect *vect)
{
	t_vect	result;
	__m256d	vec;
	__m256d	temp;
	double	result_sq[4];
	double	length;

	if (!vect)
		return (error_vect());
	vec = _mm256_loadu_pd((double *)vect);
	temp = _mm256_mul_pd(vec, vec);
	temp = _mm256_hadd_pd(temp, temp);
	_mm256_storeu_pd(result_sq, temp);
	length = sqrt(result_sq[0] + result_sq[2]);
	if (!length)
		return (error_vect());
	temp = _mm256_set1_pd(length);
	vec = _mm256_div_pd(vec, temp);
	_mm256_storeu_pd((double *)&result, vec);
	return (result);
}

double	vect_lengthsq(t_vect *vect)
{
	__m256d	vec;
	__m256d	temp;
	double	length;
	double	result_sq[4];

	vec = _mm256_loadu_pd((double *)vect);
	temp = _mm256_mul_pd(vec, vec);
	temp = _mm256_hadd_pd(temp, temp);
	_mm256_storeu_pd(result_sq, temp);
	length = result_sq[0] + result_sq[2];
	return (length);
}

double	vect_length(t_vect *vect)
{
	return (sqrt(vect_lengthsq(vect)));
}
