/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:30:28 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/02 18:36:51 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	change_shape_type(t_data *data)
{
	if (data->select->type == 5)
		data->select->type = 1;
	else
		data->select->type++;
	draw(data);
}

void	change_reflective(t_data *data)
{
	data->select->mat.reflective += 0.2;
	if (data->select->mat.reflective > 1.0)
		data->select->mat.reflective = 0.0;
	draw(data);
}

void	change_specular(t_data *data)
{
	data->select->mat.specular += 0.1;
	if (data->select->mat.specular > 1.0)
		data->select->mat.specular = 0.0;
	draw(data);
}

void	change_diffuse(t_data *data)
{
	data->select->mat.diffuse += 0.1;
	if (data->select->mat.diffuse > 1.0)
		data->select->mat.diffuse = 0.0;
	draw(data);
}

void	change_shininess(t_data *data)
{
	data->select->mat.shininess += 1.0;
	if (data->select->mat.shininess > 200.0)
		data->select->mat.shininess = 1.0;
	draw(data);
}
