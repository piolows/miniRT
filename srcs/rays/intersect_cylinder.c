/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:28:18 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 18:19:51 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	cylinder_discriminant(t_ray *ray, t_shape *cylinder, t_quadratic *q)
{
	q->a = sqr(ray->direction.x) + sqr(ray->direction.z);
	q->b = 2 * ray->origin.x * ray->direction.x
		+ 2 * ray->origin.z * ray->direction.z;
	q->c = sqr(ray->origin.x) + sqr(ray->origin.z) - 1;
	q->discriminant = sqr(q->b) - 4 * q->a * q->c;
	(void)cylinder;
}

char	check_cap_cylinder(t_ray *ray, double t)
{
	double	x;
	double	z;

	x = ray->origin.x + t * ray->direction.x;
	z = ray->origin.z + t * ray->direction.z;
	return ((sqr(x) + sqr(z)) <= 1);
}

void	intersect_caps_cyl(t_shape *c, t_ray *ray, t_inter *x, uint16_t *x_nbr)
{
	uint16_t	i;

	if (c->flag == OPEN || fabs(ray->direction.y) < OFFSET)
		return ;
	if (*x_nbr >= X_MAX - 2)
		return ;
	i = *x_nbr;
	x[i].t = (c->min - ray->origin.y) / ray->direction.y;
	if (fabs(x[i].t) > T_MIN && fabs(x[i].t) < T_MAX
		&& check_cap_cylinder(ray, x[i].t))
	{
		x[i].obj = c;
		*x_nbr += 1;
	}
	x[i + 1].t = (c->max - ray->origin.y) / ray->direction.y;
	if (fabs(x[i + 1].t) > T_MIN && fabs(x[i + 1].t) < T_MAX
		&& check_cap_cylinder(ray, x[i + 1].t))
	{
		x[i + 1].obj = c;
		if (i == *x_nbr)
			x[i] = x[i + 1];
		*x_nbr += 1;
	}
}

static inline void	intersect_cyl_ext(t_inter *x, t_quadratic *q, uint16_t i)
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

void	intersect_cylinder(t_inter *x, t_shape *c, t_ray *ray, uint16_t *x_nbr)
{
	t_quadratic	q;
	uint16_t	i;
	t_ray		t_ray;

	t_ray = scale_ray(ray, &c->inv);
	cylinder_discriminant(&t_ray, c, &q);
	if (q.a <= 0 || q.discriminant < 0 || *x_nbr >= X_MAX - 2)
		return ;
	i = *x_nbr;
	intersect_cyl_ext(x, &q, i);
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
	intersect_caps_cyl(c, &t_ray, x, x_nbr);
}
