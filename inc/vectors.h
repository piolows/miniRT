/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:00:02 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/02 19:25:12 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include "minirt.h"

typedef union u_vect
{
	double	a[4];
	struct
	{
		double	x;
		double	y;
		double	z;
		double	w;
	};
}	t_vect;

typedef union u_vect3
{
	double	a[3];
	struct
	{
		double	x;
		double	y;
		double	z;
	};
}	t_vect3;

t_vect	*new_vect(double x, double y, double z, double w);
t_vect	create_vect(double x, double y, double z, double w);
t_vect	error_vect(void);
t_vect	*copy_vect(t_vect *vect);

t_vect	add_vectors(t_vect *v1, t_vect *v2);
t_vect	subtract_vectors(t_vect *v1, t_vect *v2);
t_vect	multiply_vect(t_vect *vect, double multiplier);
t_vect	divide_vect(t_vect *vect, double divisor);
int		compare_vects(t_vect *v1, t_vect *v2);

double	dot_vect(t_vect *v1, t_vect *v2);
double	dot_vect3(t_vect3 *v1, t_vect3 *v2);
t_vect	cross_vect(t_vect *v1, t_vect *v2);
t_vect3	cross_vect3(t_vect3 *v1, t_vect3 *v2);
double	vect_length(t_vect *vect);
double	vect_lengthsq(t_vect *vect);
t_vect	normalise_vect(t_vect *vect);

void	print_vect(t_vect vect, char *name);

#endif