/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:55:20 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/15 01:15:08 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	cof_calc(t_matrix *m, int row, int column)
{
	int			i;
	int			sign;
	t_matrix3	submatrix;
	double		*submatrix_ptr;

	i = 0;
	sign = odd_even(row + column);
	submatrix_ptr = (double *)submatrix.a;
	while (i < 16)
	{
		if (i / 4 == row)
			i += 4;
		else if (i % 4 == column)
			i++;
		else
			*submatrix_ptr++ = *((double *)m->a + i++);
	}
	return (sign * determinant_tmatrix3(submatrix));
}

t_matrix	cofactor_matrix(t_matrix *m)
{
	int			i;
	t_matrix	cofactor;

	i = -1;
	while (++i < 4)
	{
		cofactor.a[i][0] = cof_calc(m, i, 0);
		cofactor.a[i][1] = cof_calc(m, i, 1);
		cofactor.a[i][2] = cof_calc(m, i, 2);
		cofactor.a[i][3] = cof_calc(m, i, 3);
	}
	return (cofactor);
}
