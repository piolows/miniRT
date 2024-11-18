/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:57:40 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 17:31:02 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static inline void	check_axis(double *origin, double *direction, double t[2])
{
	double	tmin_numerator;
	double	tmax_numerator;
	double	temp;

	tmin_numerator = -1 - *origin;
	tmax_numerator = 1 - *origin;
	if (fabs(*direction) >= EPSILON)
	{
		t[0] = tmin_numerator / *direction;
		t[1] = tmax_numerator / *direction;
	}
	else
	{
		t[0] = tmin_numerator * INFINITY;
		t[1] = tmax_numerator * INFINITY;
	}
	if (t[0] > t[1])
	{
		temp = t[1];
		t[1] = t[0];
		t[0] = temp;
	}
}

void	intersect_cube(t_inter *x, t_shape *c, t_ray *ray, uint16_t *x_nbr)
{
	uint16_t	i;
	t_ray		temp;
	double		xt[2];
	double		yt[2];
	double		zt[2];

	temp = scale_ray(ray, &c->inv);
	i = *x_nbr;
	check_axis(&temp.origin.x, &temp.direction.x, xt);
	check_axis(&temp.origin.y, &temp.direction.y, yt);
	check_axis(&temp.origin.z, &temp.direction.z, zt);
	x[i].t = get_max(xt[0], yt[0], zt[0]);
	x[i + 1].t = get_min(xt[1], yt[1], zt[1]);
	if (*x_nbr >= X_MAX - 2 || x[i].t > x[i + 1].t)
		return ;
	x[i].obj = c;
	x[i + 1].obj = c;
	if (fabs(x[i].t) > T_MIN && fabs(x[i].t) < T_MAX)
		*x_nbr += 1;
	if (fabs(x[i + 1].t) > T_MIN && fabs(x[i + 1].t) < T_MAX)
	{
		if (i == *x_nbr)
			x[i] = x[i + 1];
		*x_nbr += 1;
	}
}
