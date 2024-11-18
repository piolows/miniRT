/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:43:18 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/17 00:10:13 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	drawpximg(t_data *data, int i, int j, t_rgb colour)
{
	char	*pixel_addr;

	if (i < 0 || i > WIN_WIDTH || j < 0 || j > WIN_HEIGHT)
		return ;
	pixel_addr = data->img.addr + (j * data->img.line_length
			+ i * (data->img.bits_per_pixel / 8));
	*(unsigned int *) pixel_addr = mlx_get_color_value
		(data->mlx_ptr, rgb_to_uint(colour));
}

t_vect	calc_world_point(int p, double wall_size)
{
	t_vect	result;

	result.x = -(wall_size / 2) + (wall_size / WIN_HEIGHT) * (p % WIN_WIDTH);
	result.y = (wall_size / 2) - (wall_size / WIN_HEIGHT) * (p / WIN_WIDTH);
	result.z = 10;
	result.w = 1;
	return (result);
}

void	*draw_full_thread(void *vdata)
{
	t_draw		d;
	static int	incr;

	d.data = (t_data *)vdata;
	d.total_pixels = d.data->cam.vsize * d.data->cam.hsize;
	pthread_mutex_lock(&d.data->draw_mutex);
	d.p = d.total_pixels / N_THREADS * incr;
	incr++;
	pthread_mutex_unlock(&d.data->draw_mutex);
	d.upper_bound = d.p + d.total_pixels / N_THREADS;
	while (d.p < d.upper_bound)
	{
		d.local_ray = ray_for_pxl(&d.data->cam, d.p);
		d.colour = colour_at(&d.data->world, &d.local_ray, 4);
		drawpximg(d.data, d.p % WIN_WIDTH, d.p / WIN_WIDTH, d.colour);
		d.p++;
	}
	if (incr == N_THREADS)
		incr = 0;
	return (NULL);
}

void	draw_full(t_data *data)
{
	pthread_t	t[N_THREADS];
	int			i;

	create_image(data);
	i = 0;
	while (i < N_THREADS)
		pthread_create(&t[i++], NULL, draw_full_thread, data);
	i = 0;
	while (i < N_THREADS)
		pthread_join(t[i++], NULL);
	mlx_put_image_to_window
		(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
}

void	draw(t_data *data)
{
	if (data->world.settings.lerp)
		draw_lerp(data);
	else
		draw_full(data);
}
