/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:13:09 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/15 01:26:36 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	populate_sphere(t_line *line, t_data *data)
{
	t_shape	sp;

	sp = create_sphere(line->origin, line->diameter / 2);
	sp.mat.colour = line->colour;
	sp.mat.diffuse = line->diffuse;
	sp.mat.reflective = line->reflective;
	sp.mat.specular = line->specular;
	sp.mat.shininess = line->shininess;
	sp.mat.ambient = line->ambient;
	if (line->checker)
		sp.mat.pattern = uv_checkers(8, 8, sp.mat.colour, get_rgb(0x00FFFFFF));
	transform(&sp, scaling(line->x_scale, line->y_scale, line->z_scale), SCALE);
	if (line->x_rot)
		transform(&sp, rotation_x(line->x_rot * (M_PI / 180)), ROT);
	if (line->y_rot)
		transform(&sp, rotation_y(line->y_rot * (M_PI / 180)), ROT);
	if (line->z_rot)
		transform(&sp, rotation_z(line->z_rot * (M_PI / 180)), ROT);
	add_to_world(&data->world, sp);
}

void	populate_plane(t_line *line, t_data *data)
{
	t_shape	pl;

	pl = create_plane(line->origin, 0, 0, 0);
	pl.mat.colour = line->colour;
	transform(&pl, axis_rotation(line->normal), ROT);
	pl.mat.diffuse = line->diffuse;
	pl.mat.reflective = line->reflective;
	pl.mat.specular = line->specular;
	pl.mat.shininess = line->shininess;
	pl.mat.ambient = line->ambient;
	if (line->checker)
		pl.mat.pattern = uv_checkers(8, 8, pl.mat.colour, get_rgb(0x00FFFFFF));
	transform(&pl, scaling(line->x_scale, line->y_scale, line->z_scale), SCALE);
	if (line->x_rot)
		transform(&pl, rotation_x(line->x_rot * (M_PI / 180)), ROT);
	if (line->y_rot)
		transform(&pl, rotation_y(line->y_rot * (M_PI / 180)), ROT);
	if (line->z_rot)
		transform(&pl, rotation_z(line->z_rot * (M_PI / 180)), ROT);
	add_to_world(&data->world, pl);
}

void	populate_cylinder(t_line *line, t_data *data)
{
	t_shape	cy;

	cy = create_cylinder(line->origin, line->diameter / 2,
			-(line->height / 2), line->height / 2);
	cy.mat.colour = line->colour;
	transform(&cy, axis_rotation(line->orientation), ROT);
	cy.mat.diffuse = line->diffuse;
	cy.mat.reflective = line->reflective;
	cy.mat.specular = line->specular;
	cy.mat.shininess = line->shininess;
	cy.mat.ambient = line->ambient;
	if (line->checker)
		cy.mat.pattern = uv_checkers(8, 8, cy.mat.colour, get_rgb(0x00FFFFFF));
	transform(&cy, scaling(line->x_scale, line->y_scale, line->z_scale), SCALE);
	if (line->x_rot)
		transform(&cy, rotation_x(line->x_rot * (M_PI / 180)), ROT);
	if (line->y_rot)
		transform(&cy, rotation_y(line->y_rot * (M_PI / 180)), ROT);
	if (line->z_rot)
		transform(&cy, rotation_z(line->z_rot * (M_PI / 180)), ROT);
	add_to_world(&data->world, cy);
}

void	populate_cone(t_line *line, t_data *data)
{
	t_shape	co;

	co = create_cone(line->origin, line->diameter / 2,
			-(line->height / 2), line->height / 2);
	co.mat.colour = line->colour;
	transform(&co, axis_rotation(line->orientation), ROT);
	co.mat.diffuse = line->diffuse;
	co.mat.reflective = line->reflective;
	co.mat.specular = line->specular;
	co.mat.shininess = line->shininess;
	co.mat.ambient = line->ambient;
	if (line->checker)
		co.mat.pattern = uv_checkers(8, 8, co.mat.colour, get_rgb(0x00FFFFFF));
	transform(&co, scaling(line->x_scale, line->y_scale, line->z_scale), SCALE);
	if (line->x_rot)
		transform(&co, rotation_x(line->x_rot * (M_PI / 180)), ROT);
	if (line->y_rot)
		transform(&co, rotation_y(line->y_rot * (M_PI / 180)), ROT);
	if (line->z_rot)
		transform(&co, rotation_z(line->z_rot * (M_PI / 180)), ROT);
	add_to_world(&data->world, co);
}

void	populate_cube(t_line *line, t_data *data)
{
	t_shape	cu;

	cu = create_cube(line->origin, line->diameter / 2);
	cu.mat.colour = line->colour;
	cu.mat.diffuse = line->diffuse;
	cu.mat.reflective = line->reflective;
	cu.mat.specular = line->specular;
	cu.mat.shininess = line->shininess;
	cu.mat.ambient = line->ambient;
	if (line->checker)
		cu.mat.pattern = uv_checkers(8, 8, cu.mat.colour, get_rgb(0x00FFFFFF));
	transform(&cu, scaling(line->x_scale, line->y_scale, line->z_scale), SCALE);
	if (line->x_rot)
		transform(&cu, rotation_x(line->x_rot * (M_PI / 180)), ROT);
	if (line->y_rot)
		transform(&cu, rotation_y(line->y_rot * (M_PI / 180)), ROT);
	if (line->z_rot)
		transform(&cu, rotation_z(line->z_rot * (M_PI / 180)), ROT);
	add_to_world(&data->world, cu);
}
