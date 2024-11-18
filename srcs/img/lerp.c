/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:16:44 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/17 00:10:01 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	*draw_lerp_thread(void *vdata)
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
		if ((d.p / WIN_WIDTH) % 3 == 0)
		{
			d.local_ray = ray_for_pxl(&d.data->cam, d.p);
			d.colour = colour_at(&d.data->world, &d.local_ray, 4);
			drawpximg(d.data, d.p % WIN_WIDTH, d.p / WIN_WIDTH, d.colour);
		}
		d.p += 3;
	}
	if (incr == N_THREADS)
		incr = 0;
	return (NULL);
}

static inline void	horizontal_lerp(t_draw *d)
{
	d->p = 1;
	d->total_pixels = d->data->cam.vsize * d->data->cam.hsize;
	while (d->p < d->total_pixels)
	{
		d->colour = (t_rgb){0, 0, 0, 0};
		if ((d->p / WIN_WIDTH) % 3 == 0)
		{
			if ((d->p % WIN_WIDTH) % 3 == 1)
			{
				d->colour = get_weighted_colour_after(d->data, d->p);
				drawpximg(d->data, d->p % WIN_WIDTH,
					d->p / WIN_WIDTH, d->colour);
			}
			else if ((d->p % WIN_WIDTH) % 3 == 2)
			{
				d->colour = get_weighted_colour_before(d->data, d->p);
				drawpximg(d->data, d->p % WIN_WIDTH,
					d->p / WIN_WIDTH, d->colour);
			}
		}
		d->p++;
	}
}

static inline void	vertical_lerp(t_draw *d)
{
	d->p = 0;
	while (d->p < d->total_pixels)
	{
		d->colour = (t_rgb){0, 0, 0, 0};
		if ((d->p / WIN_WIDTH) % 3 != 0)
		{
			if ((d->p / WIN_WIDTH) % 3 == 1)
			{
				d->colour = get_weighted_colour_below(d->data, d->p);
				drawpximg(d->data, d->p % WIN_WIDTH,
					d->p / WIN_WIDTH, d->colour);
			}
			else if ((d->p / WIN_WIDTH) % 3 == 2)
			{
				d->colour = get_weighted_colour_above(d->data, d->p);
				drawpximg(d->data, d->p % WIN_WIDTH,
					d->p / WIN_WIDTH, d->colour);
			}
		}
		d->p++;
	}
}

void	draw_lerp(t_data *data)
{
	pthread_t	t[N_THREADS];
	int			i;
	t_draw		d;

	create_image(data);
	i = 0;
	while (i < N_THREADS)
		pthread_create(&t[i++], NULL, draw_lerp_thread, data);
	i = 0;
	while (i < N_THREADS)
		pthread_join(t[i++], NULL);
	d.data = data;
	horizontal_lerp(&d);
	vertical_lerp(&d);
	mlx_put_image_to_window
		(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
}
