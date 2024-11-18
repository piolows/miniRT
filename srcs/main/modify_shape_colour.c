/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_shape_colour.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:41:14 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/02 18:50:39 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	decrease_checker(t_data *data)
{
	if (data->select->checker > 0)
	{
		data->select->checker -= 2;
		data->select->mat.pattern = uv_checkers
			(data->select->checker, data->select->checker,
				data->select->mat.colour, get_rgb(0x00FFFFFF));
	}
	if (data->select->checker == 0)
		data->select->mat.pattern.type = SOLID;
	draw(data);
}

void	increase_checker(t_data *data)
{
	if (data->select->checker < 100)
		data->select->checker += 2;
	data->select->mat.pattern = uv_checkers
		(data->select->checker, data->select->checker,
			data->select->mat.colour, get_rgb(0x00FFFFFF));
	draw(data);
}

void	change_shape_red(t_data *data)
{
	data->select->mat.colour.r += 32;
	if (data->select->mat.colour.r == 256)
		data->select->mat.colour.r = 255;
	else if (data->select->mat.colour.r > 255)
		data->select->mat.colour.r = 0;
	if (data->select->checker > 0)
		data->select->mat.pattern = uv_checkers
			(data->select->checker, data->select->checker,
				data->select->mat.colour, get_rgb(0x00FFFFFF));
	draw(data);
}

void	change_shape_green(t_data *data)
{
	data->select->mat.colour.g += 32;
	if (data->select->mat.colour.g == 256)
		data->select->mat.colour.g = 255;
	else if (data->select->mat.colour.g > 255)
		data->select->mat.colour.g = 0;
	if (data->select->checker > 0)
		data->select->mat.pattern = uv_checkers
			(data->select->checker, data->select->checker,
				data->select->mat.colour, get_rgb(0x00FFFFFF));
	draw(data);
}

void	change_shape_blue(t_data *data)
{
	data->select->mat.colour.b += 32;
	if (data->select->mat.colour.b == 256)
		data->select->mat.colour.b = 255;
	else if (data->select->mat.colour.b > 255)
		data->select->mat.colour.b = 0;
	if (data->select->checker > 0)
		data->select->mat.pattern = uv_checkers
			(data->select->checker, data->select->checker,
				data->select->mat.colour, get_rgb(0x00FFFFFF));
	draw(data);
}
