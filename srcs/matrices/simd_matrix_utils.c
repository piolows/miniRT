/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simd_matrix_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:24:34 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/15 01:09:02 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	_mm256_reduce_add_pd(__m256d vec)
{
	__m128d	top;
	__m128d	bottom;
	__m128d	sum;

	top = _mm256_extractf128_pd(vec, 1);
	bottom = _mm256_castpd256_pd128(vec);
	sum = _mm_add_pd(top, bottom);
	sum = _mm_hadd_pd(sum, sum);
	return (_mm_cvtsd_f64(sum));
}

t_matrix	multiply_matrix(t_matrix *m1, double nbr)
{
	t_matrix		result;
	t_simd			simd;
	__m256d			scalar;

	simd.r1 = _mm256_loadu_pd((double *)&m1->r1);
	simd.r2 = _mm256_loadu_pd((double *)&m1->r2);
	simd.r3 = _mm256_loadu_pd((double *)&m1->r3);
	simd.r4 = _mm256_loadu_pd((double *)&m1->r4);
	scalar = _mm256_set1_pd(nbr);
	simd.r1 = _mm256_mul_pd(simd.r1, scalar);
	simd.r2 = _mm256_mul_pd(simd.r2, scalar);
	simd.r3 = _mm256_mul_pd(simd.r3, scalar);
	simd.r4 = _mm256_mul_pd(simd.r4, scalar);
	_mm256_storeu_pd(result.a[0], simd.r1);
	_mm256_storeu_pd(result.a[1], simd.r2);
	_mm256_storeu_pd(result.a[2], simd.r3);
	_mm256_storeu_pd(result.a[3], simd.r4);
	return (result);
}

t_matrix	multiply_matrices(t_matrix *m1, t_matrix *m2)
{
	t_matrix	result;
	t_simd		simd;
	t_simd		temp;
	__m256d		col;
	uint16_t	i;

	simd.r1 = _mm256_loadu_pd((double *)&m1->r1);
	simd.r2 = _mm256_loadu_pd((double *)&m1->r2);
	simd.r3 = _mm256_loadu_pd((double *)&m1->r3);
	simd.r4 = _mm256_loadu_pd((double *)&m1->r4);
	i = -1;
	while (++i < 4)
	{
		col = _mm256_set_pd(m2->a[3][i], m2->a[2][i], m2->a[1][i], m2->a[0][i]);
		temp.r1 = _mm256_mul_pd(simd.r1, col);
		temp.r2 = _mm256_mul_pd(simd.r2, col);
		temp.r3 = _mm256_mul_pd(simd.r3, col);
		temp.r4 = _mm256_mul_pd(simd.r4, col);
		result.a[0][i] = _mm256_reduce_add_pd(temp.r1);
		result.a[1][i] = _mm256_reduce_add_pd(temp.r2);
		result.a[2][i] = _mm256_reduce_add_pd(temp.r3);
		result.a[3][i] = _mm256_reduce_add_pd(temp.r4);
	}
	return (result);
}

t_vect	multiply_matrix_tvect(t_matrix *m, t_vect *vector)
{
	t_vect	result;
	t_simd	simd;
	t_simd	temp;
	__m256d	vec;

	simd.r1 = _mm256_loadu_pd((double *)&m->r1);
	simd.r2 = _mm256_loadu_pd((double *)&m->r2);
	simd.r3 = _mm256_loadu_pd((double *)&m->r3);
	simd.r4 = _mm256_loadu_pd((double *)&m->r4);
	vec = _mm256_loadu_pd((double *)vector);
	temp.r1 = _mm256_mul_pd(simd.r1, vec);
	temp.r2 = _mm256_mul_pd(simd.r2, vec);
	temp.r3 = _mm256_mul_pd(simd.r3, vec);
	temp.r4 = _mm256_mul_pd(simd.r4, vec);
	result.x = _mm256_reduce_add_pd(temp.r1);
	result.y = _mm256_reduce_add_pd(temp.r2);
	result.z = _mm256_reduce_add_pd(temp.r3);
	result.w = _mm256_reduce_add_pd(temp.r4);
	return (result);
}

t_vect	get_column(t_matrix *m, int index)
{
	t_vect	result;
	__m256d	column;

	if (!m || index < 0 || index > 3)
		return (error_vect());
	column = _mm256_set_pd(m->a[3][index], m->a[2][index],
			m->a[1][index], m->a[0][index]);
	_mm256_storeu_pd(result.a, column);
	return (result);
}
