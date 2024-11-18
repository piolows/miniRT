/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:40:56 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/17 01:27:30 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "minirt.h"

typedef union u_matrix
{
	double	a[4][4];
	struct
	{
		t_vect	r1;
		t_vect	r2;
		t_vect	r3;
		t_vect	r4;
	};
}	t_matrix;

typedef union u_matrix3
{
	double	a[3][3];
	struct
	{
		t_vect3	r1;
		t_vect3	r2;
		t_vect3	r3;
	};
}	t_matrix3;

t_matrix	*new_matrix(void);
t_matrix	populate_matrix(t_vect *r1, t_vect *r2, t_vect *r3, t_vect *r4);
t_matrix	create_identity_matrix(void);

t_matrix	multiply_matrix(t_matrix *m1, double nbr);
t_matrix	multiply_matrices(t_matrix *m1, t_matrix *m2);
t_vect		multiply_matrix_tvect(t_matrix *m, t_vect *vector);
int			compare_matrices(t_matrix *m1, t_matrix *m2);

t_matrix	inv_matrix(t_matrix *m);
double		determinant_tmatrix(t_matrix *m, t_vect *r1_cofactor);
double		determinant_tmatrix3(t_matrix3 submatrix);
double		cof_calc(t_matrix *m, int row, int column);
t_matrix	cofactor_matrix(t_matrix *m);
t_matrix	transpose_matrix(t_matrix *m1);
t_vect		get_column(t_matrix *m, int index);

t_matrix	translation(double x, double y, double z);
t_matrix	scaling(double x, double y, double z);
t_matrix	rotation_x(double r);
t_matrix	rotation_y(double r);
t_matrix	rotation_z(double r);

void		print_matrix(t_matrix *m);

#endif