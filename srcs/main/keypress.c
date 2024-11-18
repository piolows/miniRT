/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:56:41 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/17 00:11:11 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static inline void	keypress_ext_4(int keysym, t_data *data)
{
	if (keysym == K_KEY)
		data->key.k = 1;
	if (keysym == E_KEY)
		data->key.e = 1;
	if (keysym == Q_KEY)
		data->key.q = 1;
	if (keysym == F_KEY)
		toggle_flashlight(data);
	if (keysym == NUM_7)
		toggle_lerp(data);
}

static inline void	keypress_ext_3(int keysym, t_data *data)
{
	if (keysym == DOWN)
		data->key.down = 1;
	if (keysym == LEFT)
		data->key.left = 1;
	if (keysym == RIGHT)
		data->key.right = 1;
	if (keysym == SPACE)
		data->key.space = 1;
	if (keysym == LSHIFT)
		data->key.lshift = 1;
	if (keysym == DOT)
		data->key.dot = 1;
	if (keysym == COMMA)
		data->key.comma = 1;
	if (keysym == B_KEY)
		data->key.b = 1;
	if (keysym == N_KEY)
		data->key.n = 1;
	if (keysym == M_KEY)
		data->key.m = 1;
	if (keysym == H_KEY)
		data->key.h = 1;
	if (keysym == J_KEY)
		data->key.j = 1;
}

static inline void	keypress_ext_2(int keysym, t_data *data)
{
	if (data->mode == SHAPE && keysym == P_KEY)
		change_shape_blue(data);
	if (data->mode == SHAPE && keysym == T_KEY)
		change_specular(data);
	if (data->mode == SHAPE && keysym == Y_KEY)
		change_diffuse(data);
	if (data->mode == SHAPE && keysym == U_KEY)
		change_shininess(data);
	if (keysym == R_KEY)
		reset_world(data);
	if (keysym == C_KEY)
		data->mode = CAM;
	if (keysym == ESC)
		destroy_all(data, 0);
	if (keysym == W_KEY)
		data->key.w = 1;
	if (keysym == A_KEY)
		data->key.a = 1;
	if (keysym == S_KEY)
		data->key.s = 1;
	if (keysym == D_KEY)
		data->key.d = 1;
	if (keysym == UP)
		data->key.up = 1;
}

static inline void	keypress_ext(int keysym, t_data *data)
{
	if (keysym == LEFT_SQR && data->mode == SHAPE)
		decrease_checker(data);
	if (keysym == RIGHT_SQR && data->mode == SHAPE)
		increase_checker(data);
	if (keysym == NUM_1)
		new_light(data);
	if (keysym == NUM_2)
		remove_all_lights(data);
	if (keysym == Z_KEY)
		new_shape(data);
	if (data->mode == SHAPE && keysym == X_KEY)
		remove_shape(data);
	if (data->mode == CAM && keysym == I_KEY)
		change_light_red(data);
	if (data->mode == CAM && keysym == O_KEY)
		change_light_green(data);
	if (data->mode == CAM && keysym == P_KEY)
		change_light_blue(data);
	if (keysym == L_KEY)
		change_ambient_ratio(data);
	if (data->mode == SHAPE && keysym == I_KEY)
		change_shape_red(data);
	if (data->mode == SHAPE && keysym == O_KEY)
		change_shape_green(data);
}

int	keypress(int keysym, t_data *data)
{
	if (keysym == PLUS && data->move_speed < 100)
		data->move_speed += 0.05;
	if (keysym == MINUS && data->move_speed > 0.05)
		data->move_speed -= 0.05;
	if (keysym == NUM_0)
		set_superfast(data);
	if (keysym == NUM_8)
		set_shadows(data);
	if (keysym == NUM_9)
		set_reflections(data);
	if (data->mode == SHAPE && keysym == QUOTE)
		change_shape_type(data);
	if (data->mode == SHAPE && keysym == COLON)
		change_reflective(data);
	keypress_ext(keysym, data);
	keypress_ext_2(keysym, data);
	keypress_ext_3(keysym, data);
	keypress_ext_4(keysym, data);
	return (0);
}
