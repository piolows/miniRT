/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:03:46 by ppolinta          #+#    #+#             */
/*   Updated: 2024/10/20 21:26:14 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// Returns a copy vector
t_vect	*copy_vect(t_vect *vect)
{
	t_vect	*copy_temp;

	copy_temp = malloc(sizeof(t_vect));
	if (!copy_temp)
		return (NULL);
	copy_temp->x = vect->x;
	copy_temp->y = vect->y;
	copy_temp->z = vect->z;
	copy_temp->w = 1;
	return (copy_temp);
}

t_vect	error_vect(void)
{
	t_vect	vect;

	vect.x = 0;
	vect.y = 0;
	vect.z = 0;
	vect.w = -1;
	return (vect);
}

// Create and return a stack allocated vector
t_vect	create_vect(double x, double y, double z, double w)
{
	t_vect	new_temp;

	new_temp.x = x;
	new_temp.y = y;
	new_temp.z = z;
	new_temp.w = w;
	return (new_temp);
}

// Create and return a heap allocated vector
t_vect	*new_vect(double x, double y, double z, double w)
{
	t_vect	*new_temp;

	new_temp = ft_calloc(1, sizeof(t_vect));
	if (!new_temp)
		return (NULL);
	new_temp->x = x;
	new_temp->y = y;
	new_temp->z = z;
	new_temp->w = w;
	return (new_temp);
}
