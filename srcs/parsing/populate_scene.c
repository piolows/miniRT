/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:09:47 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 16:55:22 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	populate_camera(t_line *line, t_data *data)
{
	t_camera	cam;

	cam.vsize = WIN_HEIGHT;
	cam.hsize = WIN_WIDTH;
	cam.fov = line->fov / (360.0 / M_PI / 2.0);
	cam.from = line->origin;
	cam.to = add_vectors(&cam.from, &line->orientation);
	cam.up = create_vect(0, 1, 0, 0);
	cam.dir = line->orientation;
	cam.trans = view_transform(&cam.from, &cam.to, &cam.up);
	cam.inv_trans = inv_matrix(&cam.trans);
	get_pxl_size(&cam);
	data->cam = cam;
}

void	populate_ambient(t_line *line, t_data *data)
{
	data->world.ambient_rgb = line->colour;
	data->world.ambient_ratio = line->ratio;
	data->world.ambient_light = multiply_colours(&line->colour, line->ratio);
}

void	populate_light(t_line *line, t_data *data)
{
	t_rgb	colour;

	colour = multiply_colours(&line->colour, line->ratio);
	add_light(&data->world, create_point_light(line->origin, colour));
}

void	populate_scene(t_data *data)
{
	t_line	*temp;

	temp = data->line_lst;
	while (temp)
	{
		if (temp->type == LIGHT)
			populate_light(temp, data);
		if (temp->type == AMBIENT)
			populate_ambient(temp, data);
		if (temp->type == CAMERA)
			populate_camera(temp, data);
		if (temp->type == SPHERE)
			populate_sphere(temp, data);
		if (temp->type == PLANE)
			populate_plane(temp, data);
		if (temp->type == CYLINDER)
			populate_cylinder(temp, data);
		if (temp->type == CONE)
			populate_cone(temp, data);
		if (temp->type == CUBE)
			populate_cube(temp, data);
		temp = temp->next;
	}
	data->world.light[0] = create_point_light
		(data->cam.from, get_rgb(0x00FFFFFF));
}
