/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:30:52 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/02 17:42:23 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static inline void	calculate_move_vects(t_data *data, t_move *m)
{
	m->forward = subtract_vectors(&data->cam.to, &data->cam.from);
	m->forward.y = 0;
	m->forward = normalise_vect(&m->forward);
	m->left = cross_vect(&m->forward, &data->cam.up);
	m->left = normalise_vect(&m->left);
	m->up = cross_vect(&m->left, &m->forward);
	m->up = normalise_vect(&m->up);
}

void	move_shape(t_data *data)
{
	t_move	m;

	calculate_move_vects(data, &m);
	m.move = create_vect(0, 0, 0, 0);
	if (data->key.w)
		m.move = add_vectors(&m.move, &m.forward);
	if (data->key.s)
		m.move = subtract_vectors(&m.move, &m.forward);
	if (data->key.a)
		m.move = add_vectors(&m.move, &m.left);
	if (data->key.d)
		m.move = subtract_vectors(&m.move, &m.left);
	if (data->key.space)
		m.move = add_vectors(&m.move, &m.up);
	if (data->key.lshift)
		m.move = subtract_vectors(&m.move, &m.up);
	m.move.x *= data->move_speed;
	m.move.y *= data->move_speed;
	m.move.z *= data->move_speed;
	transform(data->select, translation(m.move.x, m.move.y, m.move.z), TRANSL);
	draw(data);
}

void	rotate_shape(t_data *data)
{
	if (data->key.up)
		transform(data->select, rotation_x(0.05), ROT);
	if (data->key.down)
		transform(data->select, rotation_x(-0.05), ROT);
	if (data->key.left)
		transform(data->select, rotation_y(0.05), ROT);
	if (data->key.right)
		transform(data->select, rotation_y(-0.05), ROT);
	if (data->key.q)
		transform(data->select, rotation_z(0.05), ROT);
	if (data->key.e)
		transform(data->select, rotation_z(-0.05), ROT);
	draw(data);
}

void	scale_shape(t_data *data)
{
	if (data->key.dot)
		transform(data->select, scaling(1.1, 1.1, 1.1), SCALE);
	if (data->key.comma)
		transform(data->select, scaling(0.9, 0.9, 0.9), SCALE);
	if (data->key.h)
		transform(data->select, scaling(1.1, 1.0, 1.0), SCALE);
	if (data->key.j)
		transform(data->select, scaling(1.0, 1.1, 1.0), SCALE);
	if (data->key.k)
		transform(data->select, scaling(1.0, 1.0, 1.1), SCALE);
	if (data->key.b)
		transform(data->select, scaling(0.9, 1.0, 1.0), SCALE);
	if (data->key.n)
		transform(data->select, scaling(1.0, 0.9, 1.0), SCALE);
	if (data->key.m)
		transform(data->select, scaling(1.0, 1.0, 0.9), SCALE);
	draw(data);
}
