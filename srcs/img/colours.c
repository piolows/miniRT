/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:51:24 by ppolinta          #+#    #+#             */
/*   Updated: 2024/10/20 21:03:02 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_rgb	get_rgb(unsigned int colour)
{
	t_rgb	rgb;

	rgb.a = ((colour >> 24) & 0xFF);
	rgb.r = ((colour >> 16) & 0xFF);
	rgb.g = ((colour >> 8) & 0xFF);
	rgb.b = ((colour >> 0) & 0xFF);
	if (rgb.r > 255)
		rgb.r = 255;
	else if (rgb.r < 0)
		rgb.r = 0;
	if (rgb.g > 255)
		rgb.g = 255;
	else if (rgb.g < 0)
		rgb.g = 0;
	if (rgb.b > 255)
		rgb.b = 255;
	else if (rgb.b < 0)
		rgb.b = 0;
	if (rgb.a > 255)
		rgb.a = 255;
	else if (rgb.a < 0)
		rgb.a = 0;
	return (rgb);
}

unsigned int	rgb_to_uint(t_rgb rgb)
{
	unsigned int	colour;

	colour = (rgb.a << 24) | (rgb.r << 16) | (rgb.g << 8) | (rgb.b << 0);
	return (colour);
}

unsigned int	interpolate_colour(t_rgb start_rgb, t_rgb end_rgb, double t)
{
	t_rgb			rgb;
	unsigned int	colour;

	rgb.r = (unsigned char)(start_rgb.r + t * (end_rgb.r - start_rgb.r));
	rgb.g = (unsigned char)(start_rgb.g + t * (end_rgb.g - start_rgb.g));
	rgb.b = (unsigned char)(start_rgb.b + t * (end_rgb.b - start_rgb.b));
	rgb.a = (unsigned char)(start_rgb.a + t * (end_rgb.a - start_rgb.a));
	colour = (rgb.a << 24) | (rgb.r << 16) | (rgb.g << 8) | (rgb.b << 0);
	return (colour);
}

t_rgb	convert_rgb_ratio(double r, double g, double b, double a)
{
	t_rgb	result;

	result.r = 255 * (r);
	result.g = 255 * (g);
	result.b = 255 * (b);
	result.a = 255 * (a);
	if (result.r > 255)
		result.r = 255;
	else if (result.r < 0)
		result.r = 0;
	if (result.g > 255)
		result.g = 255;
	else if (result.g < 0)
		result.g = 0;
	if (result.b > 255)
		result.b = 255;
	else if (result.b < 0)
		result.b = 0;
	if (result.a > 255)
		result.a = 255;
	else if (result.a < 0)
		result.a = 0;
	return (result);
}
