/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:51:44 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/02 19:24:00 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	reset_world(t_data *data)
{
	data->cam = data->reset_cam;
	data->world = data->reset_world;
	data->mode = CAM;
	draw(data);
}

void	new_light(t_data *data)
{
	add_light(&data->world, create_point_light(subtract_vectors
			(&data->cam.from, &data->cam.dir), get_rgb(0x00FFFFFF)));
	draw(data);
}

void	remove_all_lights(t_data *data)
{
	data->world.light_srcs = 1;
	draw(data);
}

void	new_shape(t_data *data)
{
	add_to_world(&data->world, create_cube(subtract_vectors
			(&data->cam.from, &data->cam.dir), 0.2));
	data->select = &data->world.shapes[data->world.nbr_shapes - 1];
	draw(data);
}

void	remove_shape(t_data *data)
{
	if (data->world.nbr_shapes > 0)
	{
		data->world.shapes[data->select->id]
			= data->world.shapes[data->world.nbr_shapes - 1];
		data->world.nbr_shapes--;
		refresh_shapes_id(&data->world);
		data->mode = CAM;
		draw(data);
	}
}
