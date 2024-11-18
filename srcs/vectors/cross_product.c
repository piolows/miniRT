/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:12:24 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 22:33:44 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vect	cross_vect(t_vect *v1, t_vect *v2)
{
	t_vect	cross_temp;

	cross_temp.x = v1->y * v2->z - v1->z * v2->y;
	cross_temp.y = v1->z * v2->x - v1->x * v2->z;
	cross_temp.z = v1->x * v2->y - v1->y * v2->x;
	cross_temp.w = 0;
	return (cross_temp);
}

t_vect3	cross_vect3(t_vect3 *v1, t_vect3 *v2)
{
	t_vect3	cross_temp;

	cross_temp.x = v1->y * v2->z - v1->z * v2->y;
	cross_temp.y = v1->z * v2->x - v1->x * v2->z;
	cross_temp.z = v1->x * v2->y - v1->y * v2->x;
	return (cross_temp);
}
