/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:19:33 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 15:23:15 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	parse_camera(t_line *node, char **configs, t_data *data)
{
	if (array_len(configs) < 4 || array_len(configs) > 4)
		rt_error(WR_FORMAT_C, data);
	if (!is_int(configs[3]))
		rt_error(WR_FORMAT_C, data);
	node->fov = ft_atoi(configs[3]);
	if (node->fov < 0 || node->fov > 180)
		rt_error(WR_FORMAT_C, data);
	node->origin = get_vect(configs[1], DBL, data);
	node->origin.w = 1;
	node->orientation = get_vect(configs[2], DBL, data);
	if (!is_normalised(&node->orientation, data))
		rt_error(WR_FORMAT_C, data);
	node->orientation.w = 0;
}

void	parse_light(t_line *node, char **configs, t_data *data)
{
	t_vect	colour;

	if (array_len(configs) < 4 || array_len(configs) > 4)
		rt_error(WR_FORMAT_L, data);
	if (!is_double(configs[2]))
		rt_error(WR_FORMAT_L, data);
	node->ratio = rt_atod(configs[2], data);
	if (node->ratio < 0.0 || node->ratio > 1.0)
		rt_error(WR_FORMAT_L, data);
	node->origin = get_vect(configs[1], DBL, data);
	node->origin.w = 1;
	colour = get_vect(configs[3], INT, data);
	if (colour.x < 0.0 || colour.x > 255.0
		|| colour.y < 0.0 || colour.y > 255.0
		|| colour.z < 0.0 || colour.z > 255.0)
		rt_error(WR_FORMAT_L, data);
	node->colour.r = colour.x;
	node->colour.g = colour.y;
	node->colour.b = colour.z;
	node->colour.a = 0;
}

void	parse_ambient(t_line *node, char **configs, t_data *data)
{
	t_vect	colour;

	if (array_len(configs) < 3 || array_len(configs) > 3)
		rt_error(WR_FORMAT_A, data);
	if (!is_double(configs[1]))
		rt_error(WR_FORMAT_A, data);
	node->ratio = rt_atod(configs[1], data);
	if (node->ratio < 0.0 || node->ratio > 1.0)
		rt_error(WR_FORMAT_A, data);
	colour = get_vect(configs[2], INT, data);
	if (colour.x < 0.0 || colour.x > 255.0
		|| colour.y < 0.0 || colour.y > 255.0
		|| colour.z < 0.0 || colour.z > 255.0)
		rt_error(WR_FORMAT_A, data);
	node->colour.r = colour.x;
	node->colour.g = colour.y;
	node->colour.b = colour.z;
	node->colour.a = 0;
}
