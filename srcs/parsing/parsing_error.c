/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:59:08 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 14:59:21 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	rt_error(char *err_mssg, t_data *data)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err_mssg, 2);
	if (data->rt_scene != -1)
		close(data->rt_scene);
	destroy_all(data, 1);
	exit(0);
}

void	check_file_ext(t_data *data)
{
	if (data->ac != 2)
		rt_error(WR_INPUT, data);
	if (ft_strncmp(data->av[1] + ft_strlen(data->av[1]) - 3, ".rt", 3))
		rt_error(WR_INPUT, data);
}
