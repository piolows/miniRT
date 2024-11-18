/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:52:26 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/15 01:08:02 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_matrix	multiply_matrix(t_matrix *m1, double nbr)
{
	t_matrix	result;

	result.r1 = multiply_vect(&m1->r1, nbr);
	result.r2 = multiply_vect(&m1->r2, nbr);
	result.r3 = multiply_vect(&m1->r3, nbr);
	result.r4 = multiply_vect(&m1->r4, nbr);
	return (result);
}

t_matrix	multiply_matrices(t_matrix *m1, t_matrix *m2)
{
	t_matrix	result;
	t_vect		column;
	t_vect		*row;
	int			i;

	i = -1;
	row = &(m1->r1);
	while (++i < 4)
	{
		column = get_column(m2, 0);
		result.a[i][0] = dot_vect(row + i, &column);
		column = get_column(m2, 1);
		result.a[i][1] = dot_vect(row + i, &column);
		column = get_column(m2, 2);
		result.a[i][2] = dot_vect(row + i, &column);
		column = get_column(m2, 3);
		result.a[i][3] = dot_vect(row + i, &column);
	}
	return (result);
}

t_vect	multiply_matrix_tvect(t_matrix *m, t_vect *vector)
{
	t_vect	result;

	result.x = dot_vect(&(m->r1), vector);
	result.y = dot_vect(&(m->r2), vector);
	result.z = dot_vect(&(m->r3), vector);
	result.w = dot_vect(&(m->r4), vector);
	return (result);
}

t_vect	get_column(t_matrix *m, int index)
{
	t_vect	result;

	if (!m || index < 0 || index > 3)
		return (error_vect());
	result.a[0] = m->a[0][index];
	result.a[1] = m->a[1][index];
	result.a[2] = m->a[2][index];
	result.a[3] = m->a[3][index];
	return (result);
}
