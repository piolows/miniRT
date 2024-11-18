/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:07:52 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/15 00:28:45 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	handle_input(t_data *data)
{
	if (data->mode == CAM && (data->key.w || data->key.a
			|| data->key.s || data->key.d
			|| data->key.up || data->key.down
			|| data->key.left || data->key.right
			|| data->key.space || data->key.lshift))
		move_cam(data);
	if (data->mode == SHAPE && (data->key.w || data->key.a
			|| data->key.s || data->key.d
			|| data->key.space || data->key.lshift))
		move_shape(data);
	if (data->mode == SHAPE && (data->key.up || data->key.down
			|| data->key.left || data->key.right
			|| data->key.e || data->key.q))
		rotate_shape(data);
	if (data->mode == CAM && data->key.dot)
		refresh_camera_fov(data, -0.05);
	if (data->mode == CAM && data->key.comma)
		refresh_camera_fov(data, 0.05);
	if (data->mode == SHAPE && (data->key.dot || data->key.comma
			|| data->key.b || data->key.n || data->key.m
			|| data->key.h || data->key.j || data->key.k))
		scale_shape(data);
}

int	loop(t_data *data)
{
	handle_input(data);
	return (0);
}
