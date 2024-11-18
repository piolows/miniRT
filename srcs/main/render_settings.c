/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:01:37 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 23:20:20 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	set_superfast(t_data *data)
{
	if (data->world.settings.superfast == 1)
		data->world.settings.superfast = 0;
	else if (data->world.settings.superfast == 0)
		data->world.settings.superfast = 1;
	draw(data);
}

void	set_shadows(t_data *data)
{
	if (data->world.settings.shadows == 1)
		data->world.settings.shadows = 0;
	else if (data->world.settings.shadows == 0)
		data->world.settings.shadows = 1;
	draw(data);
}

void	set_reflections(t_data *data)
{
	if (data->world.settings.reflections == 1)
		data->world.settings.reflections = 0;
	else if (data->world.settings.reflections == 0)
		data->world.settings.reflections = 1;
	draw(data);
}

void	toggle_flashlight(t_data *data)
{
	if (data->world.settings.flashlight == 1)
		data->world.settings.flashlight = 0;
	else if (data->world.settings.flashlight == 0)
		data->world.settings.flashlight = 1;
	draw(data);
}

void	toggle_lerp(t_data *data)
{
	if (data->world.settings.lerp == 1)
		data->world.settings.lerp = 0;
	else if (data->world.settings.lerp == 0)
		data->world.settings.lerp = 1;
	draw(data);
}
