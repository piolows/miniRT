/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:19:48 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 22:36:27 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	free_dblptr(void **dblptr)
{
	int	i;

	if (!dblptr)
		return ;
	i = 0;
	while (dblptr[i])
		free(dblptr[i++]);
	free(dblptr);
}

void	free_init(t_data *data)
{
	free(data);
	ft_putendl_fd("Unbelievably, malloc failed.", 2);
	exit(1);
}
