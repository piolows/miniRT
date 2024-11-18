/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:11:59 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/15 00:38:08 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static inline t_vect	apply_rotation(t_data *data, t_move *m)
{
	t_vect	forw;
	t_vect	rot;

	m->dir = subtract_vectors(&data->cam.to, &data->cam.from);
	if (m->rotation.y != 0)
	{
		m->rotation_matrix = rotation_y(m->rotation.y);
		m->dir = multiply_matrix_tvect(&m->rotation_matrix, &m->dir);
	}
	if (m->rotation.x != 0)
	{
		m->rotation_matrix = rotation_x(-m->rotation.x);
		forw = create_vect(0, 0, -1, 0);
		rot = multiply_matrix_tvect(&m->rotation_matrix, &forw);
		m->dir = multiply_matrix_tvect(&data->cam.inv_trans, &rot);
	}
	return (add_vectors(&data->cam.from, &m->dir));
}

static inline void	rotate_camera(t_data *data, t_move *m)
{
	m->rotation = create_vect(0, 0, 0, 0);
	if (data->key.left)
		m->rotation.y -= 0.05;
	else if (data->key.right)
		m->rotation.y += 0.05;
	if (data->key.up && data->cam.to.y - data->cam.from.y < 0.999)
		m->rotation.x -= 0.05;
	else if (data->key.down && data->cam.to.y - data->cam.from.y > -0.999)
		m->rotation.x += 0.05;
	data->cam.to = apply_rotation(data, m);
}

static inline void	pan_cam(t_data *data, t_move *m)
{
	if (data->key.w)
		m->move = add_vectors(&m->move, &m->forward);
	if (data->key.s)
		m->move = subtract_vectors(&m->move, &m->forward);
	if (data->key.a)
		m->move = add_vectors(&m->move, &m->left);
	if (data->key.d)
		m->move = subtract_vectors(&m->move, &m->left);
	if (data->key.space)
		m->move = add_vectors(&m->move, &m->up);
	if (data->key.lshift)
		m->move = subtract_vectors(&m->move, &m->up);
	m->move.x *= data->move_speed;
	m->move.y *= data->move_speed;
	m->move.z *= data->move_speed;
	data->cam.from = add_vectors(&data->cam.from, &m->move);
	data->cam.to = add_vectors(&data->cam.to, &m->move);
}

void	move_cam(t_data *data)
{
	t_move	m;

	m.forward = subtract_vectors(&data->cam.to, &data->cam.from);
	m.forward.y = 0;
	m.forward = normalise_vect(&m.forward);
	if (!compare_double(fabs(m.forward.x), 0)
		&& !compare_double(fabs(m.forward.z), 0))
	{
		m.forward = create_vect(0, 0, 1, 0);
		m.left = create_vect(-1, 0, 0, 0);
	}
	else
		m.left = cross_vect(&m.forward, &data->cam.up);
	m.left = normalise_vect(&m.left);
	m.up = cross_vect(&m.left, &m.forward);
	m.up = normalise_vect(&m.up);
	m.move = create_vect(0, 0, 0, 0);
	pan_cam(data, &m);
	if (data->key.left || data->key.right || data->key.up || data->key.down)
		rotate_camera(data, &m);
	data->world.light[0].point = data->cam.from;
	refresh_camera_placement(data);
}
