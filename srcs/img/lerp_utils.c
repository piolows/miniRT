/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:59:58 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/17 00:00:22 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_rgb	get_pixel_colour(t_data *data, int i, int j)
{
	unsigned int	color_value;

	if (i < 0 || i >= WIN_WIDTH || j < 0 || j >= WIN_HEIGHT)
		return ((t_rgb){0, 0, 0, 0});
	color_value = *(unsigned int *)(data->img.addr + (j * data->img.line_length
				+ i * (data->img.bits_per_pixel / 8)));
	return (get_rgb(color_value));
}

t_rgb	get_weighted_colour_after(t_data *data, int p)
{
	int		x;
	int		y;
	t_rgb	prev;
	t_rgb	next;
	t_rgb	guess;

	x = p % WIN_WIDTH;
	y = p / WIN_WIDTH;
	prev = get_pixel_colour(data, x - 1, y);
	next = get_pixel_colour(data, x + 2, y);
	guess.r = (int)((next.r * 0.6666) + (prev.r * 0.3333) + 0.5);
	guess.g = (int)((next.g * 0.6666) + (prev.g * 0.3333) + 0.5);
	guess.b = (int)((next.b * 0.6666) + (prev.b * 0.3333) + 0.5);
	guess.a = 0;
	return (guess);
}

t_rgb	get_weighted_colour_before(t_data *data, int p)
{
	int		x;
	int		y;
	t_rgb	prev;
	t_rgb	next;
	t_rgb	guess;

	x = p % WIN_WIDTH;
	y = p / WIN_WIDTH;
	prev = get_pixel_colour(data, x - 2, y);
	next = get_pixel_colour(data, x + 1, y);
	guess.r = (int)((next.r * 0.6666) + (prev.r * 0.3333) + 0.5);
	guess.g = (int)((next.g * 0.6666) + (prev.g * 0.3333) + 0.5);
	guess.b = (int)((next.b * 0.6666) + (prev.b * 0.3333) + 0.5);
	guess.a = 0;
	return (guess);
}

t_rgb	get_weighted_colour_below(t_data *data, int p)
{
	int		x;
	int		y;
	t_rgb	prev;
	t_rgb	next;
	t_rgb	guess;

	x = p % WIN_WIDTH;
	y = p / WIN_WIDTH;
	prev = get_pixel_colour(data, x, y - 1);
	next = get_pixel_colour(data, x, y + 2);
	guess.r = (int)((next.r * 0.6666) + (prev.r * 0.3333) + 0.5);
	guess.g = (int)((next.g * 0.6666) + (prev.g * 0.3333) + 0.5);
	guess.b = (int)((next.b * 0.6666) + (prev.b * 0.3333) + 0.5);
	guess.a = 0;
	return (guess);
}

t_rgb	get_weighted_colour_above(t_data *data, int p)
{
	int		x;
	int		y;
	t_rgb	prev;
	t_rgb	next;
	t_rgb	guess;

	x = p % WIN_WIDTH;
	y = p / WIN_WIDTH;
	prev = get_pixel_colour(data, x, y - 2);
	next = get_pixel_colour(data, x, y + 1);
	guess.r = (int)((prev.r * 0.6666) + (next.r * 0.3333) + 0.5);
	guess.g = (int)((prev.g * 0.6666) + (next.g * 0.3333) + 0.5);
	guess.b = (int)((prev.b * 0.6666) + (next.b * 0.3333) + 0.5);
	guess.a = 0;
	return (guess);
}
