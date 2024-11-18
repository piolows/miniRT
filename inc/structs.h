/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:01:27 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 23:19:09 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

# define LIGHT_MAX	10
# define SHAPES_MAX	50

# define CLOSED		1
# define OPEN		0

# define CAM		0
# define SHAPE		1

# define SOLID		0
# define CHECKER	1
# define CHECKER_UV	2

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
	int		a;
}	t_rgb;

typedef struct s_pattern
{
	char		type;
	t_rgb		a;
	t_rgb		b;
	int			width;
	int			height;
}	t_pattern;

typedef struct s_light
{
	t_rgb	intensity;
	t_vect	point;
}	t_light;

typedef struct s_material
{
	double			ambient;
	double			diffuse;
	double			specular;
	double			shininess;
	double			reflective;
	t_pattern		pattern;
	t_rgb			colour;
}	t_material;

typedef struct s_shape
{
	int			type;
	t_material	mat;
	t_matrix	trans;
	t_matrix	transl;
	t_matrix	rot;
	t_matrix	scale;
	t_matrix	inv;
	t_matrix	tp;
	t_vect		origin;
	t_vect		normal;
	double		radius;
	double		min;
	double		max;
	char		flag;
	int			checker;
	int			id;
}	t_shape;

typedef struct s_line
{
	int				type;
	t_vect			origin;
	t_vect			normal;
	t_vect			orientation;
	double			diameter;
	double			height;
	double			ratio;
	int				fov;
	t_rgb			colour;
	char			flag;
	double			diffuse;
	double			specular;
	double			shininess;
	double			ambient;
	double			reflective;
	int				checker;
	double			x_scale;
	double			y_scale;
	double			z_scale;
	double			x_rot;
	double			y_rot;
	double			z_rot;
	t_vect			rotation;
	char			*line;
	struct s_line	*next;
}	t_line;

typedef struct s_lighting
{
	t_shape		*shape;
	t_material	mat;
	t_light		*light;
	t_vect		point;
	t_vect		eyev;
	t_vect		normalv;
	char		in_shadow;
	t_vect		lightv;
	t_vect		reflectv;
	t_rgb		effective_colour;
	t_rgb		ambient;
	t_rgb		specular;
	t_rgb		diffuse;
	double		dot;
	double		factor;
	t_rgb		result;
}	t_lighting;

typedef struct s_intersect
{
	int					obj_type;
	int					obj_id;
	t_shape				*obj;
	double				t;
	struct s_intersect	*next;
}	t_inter;

typedef struct s_ray
{
	t_vect		origin;
	t_vect		direction;
}	t_ray;

typedef struct s_quadratic
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
}	t_quadratic;

typedef struct s_settings
{
	char	superfast;
	char	shadows;
	char	reflections;
	char	flashlight;
	char	lerp;
}	t_settings;

typedef struct s_world
{
	t_light		light[LIGHT_MAX];
	t_shape		shapes[SHAPES_MAX];
	t_rgb		ambient_rgb;
	double		ambient_ratio;
	t_rgb		ambient_light;
	uint8_t		light_srcs;
	uint16_t	nbr_shapes;
	t_settings	settings;
}	t_world;

typedef struct s_view
{
	t_vect		forward;
	t_vect		normal_up;
	t_vect		left;
	t_vect		true_up;
}	t_view;

typedef struct s_camera
{
	uint16_t		hsize;
	uint16_t		vsize;
	double			fov;
	t_matrix		trans;
	t_matrix		inv_trans;
	t_vect			from;
	t_vect			to;
	t_vect			up;
	t_vect			dir;
	double			pxl_size;
	double			half_width;
	double			half_height;
}	t_camera;

typedef struct s_comp
{
	double	t;
	t_shape	*shape;
	t_vect	eyev;
	t_vect	reflectv;
	t_vect	normalv;
	t_vect	position;
	t_vect	over_pos;
	uint8_t	inside;
}	t_comp;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_key
{
	char	w;
	char	a;
	char	s;
	char	d;
	char	q;
	char	e;
	char	b;
	char	n;
	char	m;
	char	h;
	char	j;
	char	k;
	char	up;
	char	down;
	char	left;
	char	right;
	char	space;
	char	lshift;
	char	comma;
	char	dot;
	char	ms_up;
	char	ms_down;
}	t_key;

typedef struct s_data
{
	int				ac;
	char			**av;
	int				rt_scene;
	t_line			*line_lst;
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			img;
	double			move_speed;
	t_world			world;
	t_world			reset_world;
	t_camera		cam;
	t_camera		reset_cam;
	t_ray			ray;
	t_key			key;
	pthread_mutex_t	draw_mutex;
	pthread_mutex_t	img_mutex;
	char			mode;
	t_shape			*select;
	t_light			flashlight;
}	t_data;

typedef struct s_draw
{
	t_rgb		colour;
	t_rgb		ambient;
	int			total_pixels;
	int			p;
	int			upper_bound;
	t_data		*data;
	t_ray		local_ray;
}	t_draw;

typedef struct s_move
{
	t_vect		move;
	t_vect		forward;
	t_vect		left;
	t_vect		up;
	t_vect		rotation;
	t_vect		dir;
	t_matrix	rotation_matrix;
}	t_move;

typedef struct s_simd
{
	__m256d	r1;
	__m256d	r2;
	__m256d	r3;
	__m256d	r4;
}	t_simd;

#endif