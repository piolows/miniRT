/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:07:45 by ppolinta          #+#    #+#             */
/*   Updated: 2024/10/27 00:11:06 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_rgb	hadamard_product(t_rgb *c1, t_rgb *c2)
{
	t_rgb	result;

	result.r = c1->r * (c2->r / 255.0);
	result.g = c1->g * (c2->g / 255.0);
	result.b = c1->b * (c2->b / 255.0);
	result.a = c1->a * (c2->a / 255.0);
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

t_rgb	add_colours(t_rgb *c1, t_rgb *c2)
{
	t_rgb	result;

	result.r = c1->r + c2->r;
	result.g = c1->g + c2->g;
	result.b = c1->b + c2->b;
	result.a = c1->a + c2->a;
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

t_rgb	subtract_colours(t_rgb *c1, t_rgb *c2)
{
	t_rgb	result;

	result.r = c1->r - c2->r;
	result.g = c1->g - c2->g;
	result.b = c1->b - c2->b;
	result.a = c1->a - c2->a;
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

t_rgb	multiply_colours(t_rgb *colour, double nbr)
{
	t_rgb	result;

	result.r = (colour->r * nbr);
	result.g = (colour->g * nbr);
	result.b = (colour->b * nbr);
	result.a = (colour->a * nbr);
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

t_rgb	divide_colours(t_rgb *colour, double nbr)
{
	t_rgb	result;

	result.r = colour->r / nbr;
	result.g = colour->g / nbr;
	result.b = colour->b / nbr;
	result.a = colour->a / nbr;
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
