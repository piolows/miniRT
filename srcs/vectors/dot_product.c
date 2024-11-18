/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:07:05 by ppolinta          #+#    #+#             */
/*   Updated: 2024/10/20 21:26:14 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// Returns the dot product of two vectors
double	dot_vect(t_vect *v1, t_vect *v2)
{
	if (!v1 || !v2)
		return (0);
	return (v1->x * v2->x + v1->y * v2->y
		+ v1->z * v2->z + v1->w * v2->w);
}

// Returns the dot product of two vectors
double	dot_vect3(t_vect3 *v1, t_vect3 *v2)
{
	if (!v1 || !v2)
		return (0);
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}
