/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:18:25 by ppolinta          #+#    #+#             */
/*   Updated: 2024/10/20 21:03:26 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOUR_H
# define COLOUR_H

# include "minirt.h"

t_rgb			get_rgb(unsigned int colour);
t_rgb			hadamard_product(t_rgb *c1, t_rgb *c2);
t_rgb			subtract_colours(t_rgb *c1, t_rgb *c2);
t_rgb			multiply_colours(t_rgb *colour, double nbr);
t_rgb			divide_colours(t_rgb *colour, double nbr);
t_rgb			add_colours(t_rgb *c1, t_rgb *c2);
unsigned int	interpolate_colour(t_rgb start_rgb, t_rgb end_rgb, double t);
t_rgb			convert_rgb_ratio(double r, double g, double b, double a);
unsigned int	rgb_to_uint(t_rgb rgb);

#endif