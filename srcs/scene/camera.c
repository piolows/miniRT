/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 23:44:30 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 21:33:28 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_matrix	view_transform(t_vect *from, t_vect *to, t_vect *up)
{
	t_matrix	orientation;
	t_matrix	trans_matrix;
	t_vect		world_up;
	t_view		v;

	world_up = create_vect(0, 1, 0, 0);
	v.forward = subtract_vectors(to, from);
	v.normal_up = normalise_vect(up);
	v.forward = normalise_vect(&v.forward);
	if (!compare_double(fabs(v.forward.x), 0)
		&& !compare_double(fabs(v.forward.z), 0))
		v.left = create_vect(-1, 0, 0, 0);
	else
		v.left = cross_vect(&v.forward, &world_up);
	v.true_up = cross_vect(&v.left, &v.forward);
	v.left = normalise_vect(&v.left);
	v.true_up = normalise_vect(&v.true_up);
	orientation.r1 = v.left;
	orientation.r2 = v.true_up;
	orientation.r3 = multiply_vect(&v.forward, -1);
	orientation.r4 = create_vect(0, 0, 0, 1);
	trans_matrix = translation(-from->x, -from->y, -from->z);
	orientation = multiply_matrices(&orientation, &trans_matrix);
	return (orientation);
}

void	get_pxl_size(t_camera *c)
{
	double	aspect;
	double	half_view;

	half_view = tan(c->fov / 2);
	aspect = (double)(c->hsize) / (double)(c->vsize);
	if (aspect >= 1)
	{
		c->half_width = half_view;
		c->half_height = half_view / aspect;
	}
	else
	{
		c->half_width = half_view * aspect;
		c->half_height = half_view;
	}
	c->pxl_size = (c->half_width * 2) / c->hsize;
}

t_ray	ray_for_pxl(t_camera *c, int p)
{
	double		xoffset;
	double		yoffset;
	t_vect		point;
	t_vect		pixel;
	t_vect		origin;

	xoffset = ((p % c->hsize) + 0.5) * c->pxl_size;
	yoffset = ((p / c->hsize) + 0.5) * c->pxl_size;
	point.x = c->half_width - xoffset;
	point.y = c->half_height - yoffset;
	point.z = -1;
	point.w = 1;
	pixel = multiply_matrix_tvect(&c->inv_trans, &point);
	origin = create_vect(0, 0, 0, 1);
	origin = multiply_matrix_tvect(&c->inv_trans, &origin);
	pixel = subtract_vectors(&pixel, &origin);
	pixel = normalise_vect(&pixel);
	return (create_ray(&pixel, &origin));
}

t_camera	create_default_camera(void)
{
	t_camera	result;

	result.vsize = WIN_HEIGHT;
	result.hsize = WIN_WIDTH;
	result.fov = M_PI / 3;
	result.from = create_vect(0, 1.5, -5, 1);
	result.to = create_vect(0, 1, 0, 1);
	result.up = create_vect(0, 1, 0, 0);
	result.dir = subtract_vectors(&result.from, &result.to);
	result.dir = normalise_vect(&result.dir);
	result.trans = view_transform(&result.from, &result.to, &result.up);
	result.inv_trans = inv_matrix(&result.trans);
	get_pxl_size(&result);
	return (result);
}
