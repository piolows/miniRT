/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:53:58 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/15 01:11:08 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	determinant_tmatrix3(t_matrix3 submatrix)
{
	t_vect3	cross_temp;

	cross_temp = cross_vect3(&submatrix.r2, &submatrix.r3);
	return (dot_vect3(&submatrix.r1, &cross_temp));
}

double	determinant_tmatrix(t_matrix *m, t_vect *r1_cofactor)
{
	return (dot_vect(&(m->r1), r1_cofactor));
}

t_matrix	transpose_matrix(t_matrix *m1)
{
	t_matrix	trans_temp;

	trans_temp.r1 = get_column(m1, 0);
	trans_temp.r2 = get_column(m1, 1);
	trans_temp.r3 = get_column(m1, 2);
	trans_temp.r4 = get_column(m1, 3);
	return (trans_temp);
}

t_matrix	inv_matrix(t_matrix *m)
{
	t_matrix	result;
	double		det_m;

	result = cofactor_matrix(m);
	det_m = dot_vect(&(m->r1), &(result.r1));
	if (!det_m)
		printf("not good!\n");
	result = transpose_matrix(&result);
	result = multiply_matrix(&result, 1 / det_m);
	return (result);
}
