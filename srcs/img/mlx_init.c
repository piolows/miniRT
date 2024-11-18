/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:36:09 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/02 17:41:07 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	init_keys(t_data *data)
{
	data->mode = CAM;
	data->key.w = 0;
	data->key.a = 0;
	data->key.s = 0;
	data->key.d = 0;
	data->key.up = 0;
	data->key.down = 0;
	data->key.left = 0;
	data->key.right = 0;
	data->key.space = 0;
	data->key.lshift = 0;
	data->key.comma = 0;
	data->key.dot = 0;
	data->key.b = 0;
	data->key.n = 0;
	data->key.m = 0;
	data->key.h = 0;
	data->key.j = 0;
	data->key.k = 0;
	data->key.e = 0;
	data->key.q = 0;
}

t_data	*init_mlx_data(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		free_init(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		free_init(data);
	data->win_ptr = mlx_new_window
		(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	if (!data->win_ptr)
		free_init(data);
	data->ac = ac;
	data->av = av;
	data->img.width = WIN_WIDTH;
	data->img.height = WIN_HEIGHT;
	data->move_speed = 0.2;
	data->ray.origin = create_vect(0, 0, -5, 1);
	data->ray.direction = create_vect(0, 0, 1, 0);
	pthread_mutex_init(&data->draw_mutex, NULL);
	pthread_mutex_init(&data->img_mutex, NULL);
	data->select = NULL;
	init_keys(data);
	return (data);
}

void	create_image(t_data *data)
{
	if (data->img.img_ptr)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		data->img.img_ptr = NULL;
	}
	data->img.img_ptr = mlx_new_image
		(data->mlx_ptr, data->img.width, data->img.height);
	data->img.addr = mlx_get_data_addr
		(data->img.img_ptr, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
}
