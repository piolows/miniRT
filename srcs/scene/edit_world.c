/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:29:30 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 22:15:36 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	multiply_transformations(t_shape *shape)
{
	shape->trans = shape->transl;
	shape->trans = multiply_matrices(&shape->trans, &shape->rot);
	shape->trans = multiply_matrices(&shape->trans, &shape->scale);
}

t_shape	*transform(t_shape *shape, t_matrix trans, char type)
{
	if (type == TRANSL)
		shape->transl = multiply_matrices(&shape->transl, &trans);
	else if (type == ROT)
		shape->rot = multiply_matrices(&shape->rot, &trans);
	else if (type == SCALE)
	{
		shape->scale = multiply_matrices(&shape->scale, &trans);
		if (shape->scale.r1.a[0] <= 0.000001)
			shape->scale.r1.a[0] = 0.000001;
		if (shape->scale.r2.a[1] <= 0.000001)
			shape->scale.r2.a[1] = 0.000001;
		if (shape->scale.r3.a[2] <= 0.000001)
			shape->scale.r3.a[2] = 0.000001;
	}
	multiply_transformations(shape);
	shape->inv = inv_matrix(&shape->trans);
	shape->tp = transpose_matrix(&shape->inv);
	return (shape);
}

void	refresh_shapes_id(t_world *world)
{
	int	i;

	i = 0;
	while (i < world->nbr_shapes)
	{
		world->shapes[i].id = i;
		i++;
	}
}

void	add_to_world(t_world *world, t_shape shape)
{
	if (world->nbr_shapes < SHAPES_MAX - 1)
	{
		world->shapes[world->nbr_shapes++] = shape;
		refresh_shapes_id(world);
	}
	else
		printf("Maximum number of objects reached!\n");
}

void	add_light(t_world *world, t_light light)
{
	if (world->light_srcs < LIGHT_MAX - 1)
		world->light[world->light_srcs++] = light;
	else
		printf("Maximum number of lights reached!\n");
}
