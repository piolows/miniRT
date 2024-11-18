/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:06:19 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 17:28:17 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	sphere_discriminant(t_ray *ray, t_shape *sphere, t_quadratic *q)
{
	t_vect	temp;

	q->a = dot_vect(&ray->direction, &ray->direction);
	temp = subtract_vectors(&ray->origin, &sphere->origin);
	q->b = 2 * dot_vect(&ray->direction, &temp);
	q->c = dot_vect(&temp, &temp) - 1;
	q->discriminant = (q->b * q->b) - (4 * q->a * q->c);
}

void	intersect_sphere(t_inter *x, t_shape *s, t_ray *ray, uint16_t *x_nbr)
{
	t_quadratic	q;
	uint16_t	i;
	t_ray		temp;

	if (*x_nbr >= X_MAX - 2)
		return ;
	temp = scale_ray(ray, &s->inv);
	sphere_discriminant(&temp, s, &q);
	if (q.discriminant < 0)
		return ;
	i = *x_nbr;
	x[i].obj = s;
	x[i + 1].obj = s;
	x[i].t = (-q.b - sqrt(q.discriminant)) / (2 * q.a);
	if (fabs(x[i].t) > T_MIN && fabs(x[i].t) < T_MAX)
		*x_nbr += 1;
	x[i + 1].t = (-q.b + sqrt(q.discriminant)) / (2 * q.a);
	if (fabs(x[i + 1].t) > T_MIN && fabs(x[i + 1].t) < T_MAX)
	{
		if (i == *x_nbr)
			x[i] = x[i + 1];
		*x_nbr += 1;
	}
}
