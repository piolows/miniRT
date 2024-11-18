/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:10:50 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 17:13:54 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	intersect_plane(t_inter *x, t_shape *pl, t_ray *ray, uint16_t *x_nbr)
{
	uint16_t	i;
	t_ray		t_ray;

	if (*x_nbr >= X_MAX - 1)
		return ;
	t_ray = scale_ray(ray, &pl->inv);
	if (fabs(t_ray.direction.y) < OFFSET)
		return ;
	i = *x_nbr;
	x[i].t = -t_ray.origin.y / t_ray.direction.y;
	if (fabs(x[i].t) < T_MIN || fabs(x[i].t) > T_MAX)
		return ;
	x[i].obj_id = pl->id;
	x[i].obj_type = PLANE;
	x[i].obj = pl;
	i++;
	*x_nbr = i;
}
