/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:37:42 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/17 01:28:02 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

t_vect		calc_world_point(int p, double wall_size);
t_comp		computations(t_ray *ray, t_inter *inter);
t_rgb		shade_hit(t_world *world, t_comp *comp, char recurse);
t_rgb		colour_at(t_world *world, t_ray *ray, char recurse);
char		is_shadowed(t_world *w, t_light *l, t_vect *p);
void		print_world(t_world *world);
void		populate_inter(t_world *world,
				t_ray *ray, t_inter *inter, uint16_t *x_count);

t_matrix	view_transform(t_vect *from, t_vect *to, t_vect *up);
void		get_pxl_size(t_camera *c);
t_ray		ray_for_pxl(t_camera *c, int p);

t_rgb		reflected_colour(t_world *w, t_comp *comp, char recurse);

#endif