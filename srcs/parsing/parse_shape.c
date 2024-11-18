/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:32:41 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 15:24:29 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_sphere(t_line *node, char **configs, t_data *data)
{
	t_vect	colour;

	if (array_len(configs) < 4)
		rt_error(WR_FORMAT_SP, data);
	if (!is_double(configs[2]))
		rt_error(WR_FORMAT_SP, data);
	node->diameter = rt_atod(configs[2], data);
	if (node->diameter < 0.0)
		rt_error(WR_FORMAT_SP, data);
	node->origin = get_vect(configs[1], DBL, data);
	node->origin.w = 1;
	colour = get_vect(configs[3], INT, data);
	if (colour.x < 0.0 || colour.x > 255.0
		|| colour.y < 0.0 || colour.y > 255.0
		|| colour.z < 0.0 || colour.z > 255.0)
		rt_error(WR_FORMAT_SP, data);
	node->colour.r = colour.x;
	node->colour.g = colour.y;
	node->colour.b = colour.z;
	node->colour.a = 0;
	parse_options(node, configs + 4, data);
}

void	parse_plane(t_line *node, char **configs, t_data *data)
{
	t_vect	colour;

	if (array_len(configs) < 4)
		rt_error(WR_FORMAT_P, data);
	node->origin = get_vect(configs[1], DBL, data);
	node->origin.w = 1;
	node->normal = get_vect(configs[2], DBL, data);
	if (!is_normalised(&node->normal, data))
		rt_error(WR_FORMAT_P, data);
	node->normal.w = 0;
	colour = get_vect(configs[3], INT, data);
	if (colour.x < 0.0 || colour.x > 255.0
		|| colour.y < 0.0 || colour.y > 255.0
		|| colour.z < 0.0 || colour.z > 255.0)
		rt_error(WR_FORMAT_P, data);
	node->colour.r = colour.x;
	node->colour.g = colour.y;
	node->colour.b = colour.z;
	node->colour.a = 0;
	parse_options(node, configs + 4, data);
}

void	parse_cylinder(t_line *node, char **configs, t_data *data)
{
	t_vect	colour;

	if (array_len(configs) < 6)
		rt_error(WR_FORMAT_CY, data);
	if (!is_double(configs[3]) || !is_double(configs[4]))
		rt_error(WR_FORMAT_CY, data);
	node->diameter = rt_atod(configs[3], data);
	node->height = rt_atod(configs[4], data);
	if (node->diameter < 0.0 || node->height < 0.0)
		rt_error(WR_FORMAT_CY, data);
	node->origin = get_vect(configs[1], DBL, data);
	node->origin.w = 1;
	node->orientation = get_vect(configs[2], DBL, data);
	if (!is_normalised(&node->orientation, data))
		rt_error(WR_FORMAT_CY, data);
	node->orientation.w = 0;
	colour = get_vect(configs[5], INT, data);
	if (colour.x < 0.0 || colour.x > 255.0 || colour.y < 0.0
		|| colour.y > 255.0 || colour.z < 0.0 || colour.z > 255.0)
		rt_error(WR_FORMAT_CY, data);
	node->colour.r = colour.x;
	node->colour.g = colour.y;
	node->colour.b = colour.z;
	node->colour.a = 0;
	parse_options(node, configs + 6, data);
}

void	parse_cone(t_line *node, char **configs, t_data *data)
{
	t_vect	colour;

	if (array_len(configs) < 6)
		rt_error(WR_FORMAT_CO, data);
	if (!is_double(configs[3]) || !is_double(configs[4]))
		rt_error(WR_FORMAT_CO, data);
	node->diameter = rt_atod(configs[3], data);
	node->height = rt_atod(configs[4], data);
	if (node->diameter < 0.0 || node->height < 0.0)
		rt_error(WR_FORMAT_CO, data);
	node->origin = get_vect(configs[1], DBL, data);
	node->origin.w = 1;
	node->orientation = get_vect(configs[2], DBL, data);
	if (!is_normalised(&node->orientation, data))
		rt_error(WR_FORMAT_CO, data);
	node->orientation.w = 0;
	colour = get_vect(configs[5], INT, data);
	if (colour.x < 0.0 || colour.x > 255.0 || colour.y < 0.0
		|| colour.y > 255.0 || colour.z < 0.0 || colour.z > 255.0)
		rt_error(WR_FORMAT_CO, data);
	node->colour.r = colour.x;
	node->colour.g = colour.y;
	node->colour.b = colour.z;
	node->colour.a = 0;
	parse_options(node, configs + 6, data);
}

void	parse_cube(t_line *node, char **configs, t_data *data)
{
	t_vect	colour;

	if (array_len(configs) < 4)
		rt_error(WR_FORMAT_CU, data);
	if (!is_double(configs[2]))
		rt_error(WR_FORMAT_CU, data);
	node->diameter = rt_atod(configs[2], data);
	if (node->diameter < 0.0)
		rt_error(WR_FORMAT_CU, data);
	node->origin = get_vect(configs[1], DBL, data);
	node->origin.w = 1;
	colour = get_vect(configs[3], INT, data);
	if (colour.x < 0.0 || colour.x > 255.0
		|| colour.y < 0.0 || colour.y > 255.0
		|| colour.z < 0.0 || colour.z > 255.0)
		rt_error(WR_FORMAT_CU, data);
	node->colour.r = colour.x;
	node->colour.g = colour.y;
	node->colour.b = colour.z;
	node->colour.a = 0;
	parse_options(node, configs + 4, data);
}
