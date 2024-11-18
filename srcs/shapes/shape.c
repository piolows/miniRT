/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:11:29 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 22:29:30 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	default_shape_values(t_shape *shape)
{
	shape->mat = create_default_material();
	shape->trans = create_identity_matrix();
	shape->transl = shape->trans;
	shape->rot = shape->trans;
	shape->scale = shape->trans;
	shape->inv = shape->trans;
	shape->tp = shape->trans;
	shape->origin = create_vect(0, 0, 0, 1);
	shape->normal = create_vect(0, 1, 0, 0);
	shape->min = -1;
	shape->max = 1;
	shape->flag = CLOSED;
	shape->checker = 0;
}
