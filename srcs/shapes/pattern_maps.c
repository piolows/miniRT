/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:27:56 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 22:28:31 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	cylindrical_map(t_vect point, double uv[2])
{
	double	theta;
	double	raw_u;

	theta = atan2(point.x, point.z);
	raw_u = theta / (2 * M_PI);
	uv[0] = 1 - (raw_u + 0.5);
	uv[1] = point.y - floor(point.y);
}

void	planar_map(t_vect point, double uv[2])
{
	double	temp;

	uv[0] = modf(point.x, &temp);
	uv[1] = modf(point.z, &temp);
}

void	spherical_map(t_vect point, double uv[2])
{
	double	theta;
	double	radius;
	double	phi;
	double	raw_u;

	theta = atan2(point.x, point.z);
	radius = vect_length(&point);
	phi = acos(point.y / radius);
	raw_u = theta / (2 * M_PI);
	uv[0] = 1 - (raw_u + 0.5);
	uv[1] = 1 - phi / M_PI;
}
