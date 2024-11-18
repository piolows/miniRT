/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:49:27 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/03 22:31:55 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static inline void	keyrelease_ext(int keysym, t_data *data)
{
	if (keysym == SPACE)
		data->key.space = 0;
	if (keysym == LSHIFT)
		data->key.lshift = 0;
	if (keysym == DOT)
		data->key.dot = 0;
	if (keysym == COMMA)
		data->key.comma = 0;
	if (keysym == B_KEY)
		data->key.b = 0;
	if (keysym == N_KEY)
		data->key.n = 0;
	if (keysym == M_KEY)
		data->key.m = 0;
	if (keysym == H_KEY)
		data->key.h = 0;
	if (keysym == J_KEY)
		data->key.j = 0;
	if (keysym == K_KEY)
		data->key.k = 0;
	if (keysym == E_KEY)
		data->key.e = 0;
	if (keysym == Q_KEY)
		data->key.q = 0;
}

int	keyrelease(int keysym, t_data *data)
{
	if (keysym == TILDE)
		print_manual();
	if (keysym == W_KEY)
		data->key.w = 0;
	if (keysym == A_KEY)
		data->key.a = 0;
	if (keysym == S_KEY)
		data->key.s = 0;
	if (keysym == D_KEY)
		data->key.d = 0;
	if (keysym == UP)
		data->key.up = 0;
	if (keysym == DOWN)
		data->key.down = 0;
	if (keysym == LEFT)
		data->key.left = 0;
	if (keysym == RIGHT)
		data->key.right = 0;
	keyrelease_ext(keysym, data);
	return (0);
}
