/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:15:42 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 17:52:57 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

char	check_cap_cone(t_ray *ray, double t, double y)
{
	double	x;
	double	z;

	x = ray->origin.x + t * ray->direction.x;
	z = ray->origin.z + t * ray->direction.z;
	return ((sqr(x) + sqr(z)) <= sqr(y));
}

void	intersect_caps_cone(t_shape *c, t_ray *ray, t_inter *x, uint16_t *x_nbr)
{
	uint16_t	i;

	if (c->flag == OPEN || fabs(ray->direction.y) < OFFSET)
		return ;
	if (*x_nbr >= X_MAX - 2)
		return ;
	i = *x_nbr;
	x[i].t = (c->min - ray->origin.y) / ray->direction.y;
	if (fabs(x[i].t) > T_MIN && fabs(x[i].t) < T_MAX
		&& check_cap_cone(ray, x[i].t, c->min))
	{
		x[i].obj = c;
		*x_nbr += 1;
	}
	x[i + 1].t = (c->max - ray->origin.y) / ray->direction.y;
	if (fabs(x[i + 1].t) > T_MIN && fabs(x[i + 1].t) < T_MAX
		&& check_cap_cone(ray, x[i + 1].t, c->max))
	{
		x[i + 1].obj = c;
		if (i == *x_nbr)
			x[i] = x[i + 1];
		*x_nbr += 1;
	}
}

void	cone_discriminant(t_ray *r, t_shape *cone, t_quadratic *q)
{
	q->a = sqr(r->direction.x) - sqr(r->direction.y) + sqr(r->direction.z);
	q->b = 2 * r->origin.x * r->direction.x
		- 2 * r->origin.y * r->direction.y
		+ 2 * r->origin.z * r->direction.z;
	q->c = sqr(r->origin.x) - sqr(r->origin.y) + sqr(r->origin.z);
	q->discriminant = sqr(q->b) - 4 * q->a * q->c;
	(void)cone;
}

static inline void	intersect_cone_ext(t_inter *x, t_quadratic *q, uint16_t i)
{
	if (fabs(q->a) <= OFFSET)
	{
		if (q->b <= OFFSET)
			return ;
		x[i].t = -q->c / (2 * q->b);
		x[i + 1].t = x[i].t;
	}
	else
	{
		if (q->b < 0)
		{
			x[i].t = (-q->b + sqrt(q->discriminant)) / (2 * q->a);
			x[i + 1].t = (-q->b - sqrt(q->discriminant)) / (2 * q->a);
		}
		else
		{
			x[i].t = (-q->b - sqrt(q->discriminant)) / (2 * q->a);
			x[i + 1].t = (-q->b + sqrt(q->discriminant)) / (2 * q->a);
		}
	}
}

void	intersect_cone(t_inter *x, t_shape *c, t_ray *ray, uint16_t *x_nbr)
{
	t_quadratic	q;
	uint16_t	i;
	t_ray		t_ray;

	t_ray = scale_ray(ray, &c->inv);
	cone_discriminant(&t_ray, c, &q);
	if (q.discriminant < 0 || *x_nbr >= X_MAX - 2)
		return ;
	i = *x_nbr;
	intersect_cone_ext(x, &q, i);
	x[i].obj = c;
	x[i + 1].obj = c;
	q.a = t_ray.origin.y + t_ray.direction.y * x[i].t;
	q.b = t_ray.origin.y + t_ray.direction.y * x[i + 1].t;
	if (q.a > c->min && q.a < c->max
		&& fabs(x[i].t) > T_MIN && fabs(x[i].t) < T_MAX)
		*x_nbr += 1;
	if (q.b > c->min && q.b < c->max
		&& fabs(x[i + 1].t) > T_MIN && fabs(x[i + 1].t) < T_MAX)
	{
		if (i == *x_nbr)
			x[i] = x[i + 1];
		*x_nbr += 1;
	}
	intersect_caps_cone(c, &t_ray, x, x_nbr);
}
