/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:24:51 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/17 00:26:44 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <pthread.h>
# include <immintrin.h>
# include <inttypes.h>

# include "vectors.h"
# include "matrices.h"
# include "structs.h"
# include "rays.h"
# include "colour.h"
# include "shapes.h"
# include "light.h"
# include "scene.h"
# include "parsing.h"

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define WHITE		"\x1b[0;37m"
# define BOLD		"\x1b[1m"
# define RESET		"\x1b[0m"

# define POINT		1
# define VECTOR		0
# define EPSILON	0.0000001
# define OFFSET		0.0000001
# define DIMENSION	4

# define LIGHT		0
# define CUBE		1
# define SPHERE		2
# define CYLINDER	3
# define CONE		4
# define PLANE		5
# define CAMERA		6
# define AMBIENT	7
# define SKIP		-1

# define TRANSL		1
# define ROT		2
# define SCALE		3

# define WIN_WIDTH	1664
# define WIN_HEIGHT	936

# define N_THREADS	24

# ifdef __APPLE__
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define R_KEY 15
#  define Q_KEY 12
#  define E_KEY 14
#  define C_KEY 8
#  define B_KEY 11
#  define N_KEY 45
#  define M_KEY 46
#  define H_KEY 4
#  define J_KEY 38
#  define K_KEY 40
#  define Z_KEY 6
#  define X_KEY 7
#  define I_KEY 34
#  define O_KEY 31
#  define P_KEY 35
#  define L_KEY 37
#  define T_KEY 17
#  define Y_KEY 16
#  define U_KEY 32
#  define F_KEY 3
#  define UP 126
#  define LEFT 123
#  define DOWN 125
#  define RIGHT 124
#  define SPACE 49
#  define LSHIFT 257
#  define COMMA 43
#  define DOT 47
#  define MINUS 27
#  define PLUS 24
#  define COLON 41
#  define QUOTE 39
#  define LEFT_SQR 33
#  define RIGHT_SQR 30
#  define NUM_0 29
#  define NUM_1 18
#  define NUM_2 19
#  define NUM_3 20
#  define NUM_4 21
#  define NUM_5 23
#  define NUM_6 22
#  define NUM_7 26
#  define NUM_8 28
#  define NUM_9 25
#  define TILDE 50
#  define ESC 53
# else
#  define W_KEY 119
#  define A_KEY 97
#  define S_KEY 115
#  define D_KEY 100
#  define R_KEY 114
#  define Q_KEY 113
#  define E_KEY 101
#  define C_KEY 99
#  define B_KEY 98
#  define N_KEY 110
#  define M_KEY 109
#  define H_KEY 104
#  define J_KEY 106
#  define K_KEY 107
#  define Z_KEY 122
#  define X_KEY 120
#  define I_KEY 105
#  define O_KEY 111
#  define P_KEY 112
#  define L_KEY 108
#  define T_KEY 116
#  define Y_KEY 121
#  define U_KEY 117
#  define F_KEY 102
#  define UP 65362
#  define LEFT 65361
#  define DOWN 65364
#  define RIGHT 65363
#  define SPACE 32
#  define LSHIFT 65505
#  define COMMA 44
#  define DOT 46
#  define MINUS 45
#  define PLUS 61
#  define COLON 59
#  define QUOTE 39
#  define LEFT_SQR 91
#  define RIGHT_SQR 93
#  define NUM_0 48
#  define NUM_1 49
#  define NUM_2 50
#  define NUM_3 51
#  define NUM_4 52
#  define NUM_5 53
#  define NUM_6 54
#  define NUM_7 55
#  define NUM_8 56
#  define NUM_9 57
#  define TILDE 96
#  define ESC 65307
# endif

t_data			*init_mlx_data(int ac, char **av);
void			create_image(t_data *data);

void			draw(t_data *data);
void			draw_full(t_data *data);
void			draw_lerp(t_data *data);
void			drawpximg(t_data *data, int i, int j, t_rgb colour);
t_rgb			get_weighted_colour_above(t_data *data, int p);
t_rgb			get_weighted_colour_below(t_data *data, int p);
t_rgb			get_weighted_colour_before(t_data *data, int p);
t_rgb			get_weighted_colour_after(t_data *data, int p);
t_rgb			get_pixel_colour(t_data *data, int i, int j);

void			free_init(t_data *data);
void			free_data(t_data *data);
void			free_dblptr(void **dblptr);
void			free_list(t_data *data);

double			sqr(double nbr);
int				compare_double(double a, double b);
int				odd_even(int nbr);
double			get_max(double a, double b, double c);
double			get_min(double a, double b, double c);

void			move_cam(t_data *data);
void			move_shape(t_data *data);
void			rotate_shape(t_data *data);
void			scale_shape(t_data *data);
void			refresh_camera_placement(t_data *data);
void			refresh_camera_fov(t_data *data, double incr);

t_shape			*transform(t_shape *shape, t_matrix trans, char type);
void			*change_colour(void *shape, t_rgb rgb);
t_material		*get_material_ptr(void *shape);
void			add_to_world(t_world *world, t_shape shape);
void			add_light(t_world *world, t_light light);
t_world			create_default_world(void);

int				keypress(int keysym, t_data *data);
int				keyrelease(int keysym, t_data *data);
int				loop(t_data *data);

void			destroy_all(t_data *data, int e);
double			_mm256_reduce_add_pd(__m256d vec);

void			print_manual(void);
void			set_superfast(t_data *data);
void			set_shadows(t_data *data);
void			set_reflections(t_data *data);
void			change_shape_type(t_data *data);
void			change_reflective(t_data *data);
void			change_specular(t_data *data);
void			change_diffuse(t_data *data);
void			change_shininess(t_data *data);
void			increase_checker(t_data *data);
void			decrease_checker(t_data *data);
void			change_shape_red(t_data *data);
void			change_shape_green(t_data *data);
void			change_shape_blue(t_data *data);
void			new_shape(t_data *data);
void			remove_shape(t_data *data);
void			new_light(t_data *data);
void			remove_all_lights(t_data *data);
void			change_light_red(t_data *data);
void			change_light_green(t_data *data);
void			change_light_blue(t_data *data);
void			change_ambient_ratio(t_data *data);
void			reset_world(t_data *data);
void			toggle_flashlight(t_data *data);
void			toggle_lerp(t_data *data);

#endif