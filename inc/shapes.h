/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:30:30 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/17 01:29:14 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "minirt.h"

void		default_shape_values(t_shape *shape);
t_material	create_default_material(void);
t_material	get_material(void *shape);

t_vect		normal_calc(t_shape *shape, t_vect *point);

t_shape		create_sphere(t_vect point, double radius);
void		sphere_discriminant(t_ray *ray, t_shape *sphere, t_quadratic *q);
void		intersect_sphere(t_inter *x,
				t_shape *s, t_ray *ray, uint16_t *x_nbr);

t_shape		create_plane(t_vect point,
				double rot_x, double rot_y, double rot_z);
void		intersect_plane(t_inter *x,
				t_shape *plane, t_ray *ray, uint16_t *x_nbr);

t_shape		create_cylinder(t_vect point,
				double radius, double min, double max);
void		intersect_cylinder(t_inter *x,
				t_shape *c, t_ray *ray, uint16_t *x_nbr);
void		intersect_caps_cylinder(t_shape *c,
				t_ray *ray, t_inter *x, uint16_t *x_nbr);
char		check_cap_cylinder(t_ray *ray, double t);

t_shape		create_cone(t_vect point, double radius, double min, double max);
char		check_cap_cone(t_ray *ray, double t, double y);
void		intersect_cone(t_inter *x, t_shape *c, t_ray *ray, uint16_t *x_nbr);
void		intersect_caps_cone(t_shape *c,
				t_ray *ray, t_inter *x, uint16_t *x_nbr);

t_shape		create_cube(t_vect point, double radius);
void		intersect_cube(t_inter *x, t_shape *c, t_ray *ray, uint16_t *x_nbr);

t_pattern	checker_pattern(t_rgb a, t_rgb b);
t_rgb		*checker_at(t_pattern *pattern, t_vect point, int type);
t_rgb		*checker_at_object(t_pattern *pattern,
				t_shape *shape, t_vect *point);

t_pattern	uv_checkers(int width, int height, t_rgb a, t_rgb b);

void		transform_pattern(t_pattern *p, t_matrix trans, char type);

void		refresh_shapes_id(t_world *world);
t_vect		normal_cube(t_shape *c, t_vect *point);
t_vect		normal_cone(t_shape *c, t_vect *point);
t_vect		normal_cylinder(t_shape *c, t_vect *point);
t_vect		normal_plane(t_shape *p, t_vect *point);
t_vect		normal_sphere(t_shape *s, t_vect *point);

void		spherical_map(t_vect point, double uv[2]);
void		planar_map(t_vect point, double uv[2]);
void		cylindrical_map(t_vect point, double uv[2]);

#endif