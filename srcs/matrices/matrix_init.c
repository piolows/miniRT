/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:51:45 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/15 01:12:54 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_matrix	create_identity_matrix(void)
{
	t_matrix	result;

	result.r1 = create_vect(1, 0, 0, 0);
	result.r2 = create_vect(0, 1, 0, 0);
	result.r3 = create_vect(0, 0, 1, 0);
	result.r4 = create_vect(0, 0, 0, 1);
	return (result);
}

t_matrix	*new_matrix(void)
{
	t_matrix	*temp;

	temp = ft_calloc(1, sizeof(t_matrix));
	if (!temp)
		return (NULL);
	return (temp);
}

t_matrix	populate_matrix(t_vect *r1, t_vect *r2, t_vect *r3, t_vect *r4)
{
	t_matrix	result;

	result.r1 = *r1;
	result.r2 = *r2;
	result.r3 = *r3;
	result.r4 = *r4;
	return (result);
}
