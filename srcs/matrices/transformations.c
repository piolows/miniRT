/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 02:06:56 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/15 01:13:38 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_matrix	translation(double x, double y, double z)
{
	t_matrix	matrix;

	matrix.r1 = create_vect(1, 0, 0, x);
	matrix.r2 = create_vect(0, 1, 0, y);
	matrix.r3 = create_vect(0, 0, 1, z);
	matrix.r4 = create_vect(0, 0, 0, 1);
	return (matrix);
}

t_matrix	scaling(double x, double y, double z)
{
	t_matrix	matrix;

	matrix.r1 = create_vect(x, 0, 0, 0);
	matrix.r2 = create_vect(0, y, 0, 0);
	matrix.r3 = create_vect(0, 0, z, 0);
	matrix.r4 = create_vect(0, 0, 0, 1);
	return (matrix);
}

t_matrix	rotation_x(double r)
{
	t_matrix	matrix;

	matrix.r1 = create_vect(1, 0, 0, 0);
	matrix.r2 = create_vect(0, cos(r), -sin(r), 0);
	matrix.r3 = create_vect(0, sin(r), cos(r), 0);
	matrix.r4 = create_vect(0, 0, 0, 1);
	return (matrix);
}

t_matrix	rotation_y(double r)
{
	t_matrix	matrix;

	matrix.r1 = create_vect(cos(r), 0, sin(r), 0);
	matrix.r2 = create_vect(0, 1, 0, 0);
	matrix.r3 = create_vect(-sin(r), 0, cos(r), 0);
	matrix.r4 = create_vect(0, 0, 0, 1);
	return (matrix);
}

t_matrix	rotation_z(double r)
{
	t_matrix	matrix;

	matrix.r1 = create_vect(cos(r), -sin(r), 0, 0);
	matrix.r2 = create_vect(sin(r), cos(r), 0, 0);
	matrix.r3 = create_vect(0, 0, 1, 0);
	matrix.r4 = create_vect(0, 0, 0, 1);
	return (matrix);
}
