/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:43:34 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/17 01:27:41 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "minirt.h"

# define X_MAX	100

# define T_MAX	1.0e30
# define T_MIN	0.0001

t_ray		*new_ray(t_vect *vector, t_vect *point);
t_ray		create_ray(t_vect *vector, t_vect *point);
t_vect		position(t_ray *ray, double t);
void		print_ray(t_ray ray);

t_ray		scale_ray(t_ray *ray, t_matrix *trans);
t_vect		reflect(t_vect *lp, t_vect *n);

void		intersect(t_shape *shape, t_ray *ray, t_inter *inter, uint16_t *x);
void		print_x_array(t_inter *x);
void		sort_x_array(t_inter *inter);

t_inter		*get_hit(t_inter *inter, uint16_t *x_count);

#endif