/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:34:23 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 21:34:51 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	refresh_camera_placement(t_data *data)
{
	data->cam.trans = view_transform(&data->cam.from,
			&data->cam.to, &data->cam.up);
	data->cam.inv_trans = inv_matrix(&data->cam.trans);
	data->cam.dir = subtract_vectors(&data->cam.from, &data->cam.to);
	data->cam.dir = normalise_vect(&data->cam.dir);
	draw(data);
}

void	refresh_camera_fov(t_data *data, double incr)
{
	data->cam.fov += incr;
	get_pxl_size(&data->cam);
	draw(data);
}
