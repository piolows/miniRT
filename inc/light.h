/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:55:15 by ppolinta          #+#    #+#             */
/*   Updated: 2024/10/31 15:41:15 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "minirt.h"

t_light	create_point_light(t_vect pos, t_rgb intensity);
t_rgb	lighting(t_lighting *l);

// t_rgb	lighting(t_light *light, t_vect *point, void *shape, t_ray *ray);

#endif