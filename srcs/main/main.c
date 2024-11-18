/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:25:20 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/17 00:49:32 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	destroy_all(t_data *data, int e)
{
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	pthread_mutex_destroy(&data->draw_mutex);
	pthread_mutex_destroy(&data->img_mutex);
	free_list(data);
	free(data);
	ft_putendl_fd("miniRT exited.", 1);
	exit(e);
}

int	exit_button(t_data *data)
{
	destroy_all(data, 0);
	return (0);
}

int	mouse(int button, int x, int y, t_data *data)
{
	t_ray		ray;
	t_inter		x_arr[X_MAX];
	uint16_t	x_nbr;
	t_inter		*hit;

	x_nbr = 0;
	if (button == 1 && x >= 0 && y >= 0)
	{
		ray = ray_for_pxl(&data->cam, WIN_WIDTH * y + x);
		populate_inter(&data->world, &ray, x_arr, &x_nbr);
		hit = get_hit(x_arr, &x_nbr);
		if (hit)
		{
			data->mode = SHAPE;
			data->select = hit->obj;
		}
	}
	if (button == 4)
		refresh_camera_fov(data, -0.05);
	if (button == 5)
		refresh_camera_fov(data, 0.05);
	return (0);
}

t_settings	default_settings(void)
{
	t_settings	s;

	s.shadows = 1;
	s.reflections = 1;
	s.superfast = 0;
	s.flashlight = 0;
	s.lerp = 0;
	return (s);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = init_mlx_data(ac, av);
	data->world.light_srcs = 1;
	data->world.nbr_shapes = 0;
	process_file(data);
	data->world.settings = default_settings();
	data->reset_world = data->world;
	data->reset_cam = data->cam;
	draw(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, &keypress, data);
	mlx_hook(data->win_ptr, 3, 1L << 1, &keyrelease, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, &exit_button, data);
	mlx_hook(data->win_ptr, 4, 1L << 2, &mouse, data);
	mlx_loop_hook(data->mlx_ptr, &loop, data);
	mlx_loop(data->mlx_ptr);
	destroy_all(data, 0);
	return (0);
}
