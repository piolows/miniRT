/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:07:57 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/02 19:23:25 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	change_ambient_ratio(t_data *data)
{
	data->world.ambient_ratio += 0.1;
	if (data->world.ambient_ratio > 1.0)
		data->world.ambient_ratio = 0.0;
	data->world.ambient_light = multiply_colours
		(&data->world.ambient_rgb, data->world.ambient_ratio);
	draw(data);
}

void	change_light_red(t_data *data)
{
	if (data->world.light_srcs == 1 && !data->world.settings.flashlight)
	{
		data->world.ambient_rgb.r += 32;
		if (data->world.ambient_rgb.r == 256)
			data->world.ambient_rgb.r = 255;
		else if (data->world.ambient_rgb.r > 255)
			data->world.ambient_rgb.r = 0;
		data->world.ambient_light = multiply_colours
			(&data->world.ambient_rgb, data->world.ambient_ratio);
	}
	else
	{
		data->world.light[data->world.light_srcs - 1].intensity.r += 32;
		if (data->world.light[data->world.light_srcs - 1].intensity.r == 256)
			data->world.light[data->world.light_srcs - 1].intensity.r = 255;
		else if
			(data->world.light[data->world.light_srcs - 1].intensity.r > 255)
			data->world.light[data->world.light_srcs - 1].intensity.r = 0;
	}
	draw(data);
}

void	change_light_green(t_data *data)
{
	if (data->world.light_srcs == 1 && !data->world.settings.flashlight)
	{
		data->world.ambient_rgb.g += 32;
		if (data->world.ambient_rgb.g == 256)
			data->world.ambient_rgb.g = 255;
		else if (data->world.ambient_rgb.g > 255)
			data->world.ambient_rgb.g = 0;
		data->world.ambient_light = multiply_colours
			(&data->world.ambient_rgb, data->world.ambient_ratio);
	}
	else
	{
		data->world.light[data->world.light_srcs - 1].intensity.g += 32;
		if (data->world.light[data->world.light_srcs - 1].intensity.g == 256)
			data->world.light[data->world.light_srcs - 1].intensity.g = 255;
		else if
			(data->world.light[data->world.light_srcs - 1].intensity.g > 255)
			data->world.light[data->world.light_srcs - 1].intensity.g = 0;
	}
	draw(data);
}

void	change_light_blue(t_data *data)
{
	if (data->world.light_srcs == 1 && !data->world.settings.flashlight)
	{
		data->world.ambient_rgb.b += 32;
		if (data->world.ambient_rgb.b == 256)
			data->world.ambient_rgb.b = 255;
		else if (data->world.ambient_rgb.b > 255)
			data->world.ambient_rgb.b = 0;
		data->world.ambient_light = multiply_colours
			(&data->world.ambient_rgb, data->world.ambient_ratio);
	}
	else
	{
		data->world.light[data->world.light_srcs - 1].intensity.b += 32;
		if (data->world.light[data->world.light_srcs - 1].intensity.b == 256)
			data->world.light[data->world.light_srcs - 1].intensity.b = 255;
		else if
			(data->world.light[data->world.light_srcs - 1].intensity.b > 255)
			data->world.light[data->world.light_srcs - 1].intensity.b = 0;
	}
	draw(data);
}
