/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:49:06 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 15:24:47 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	default_options(t_line *node)
{
	node->diffuse = 0.9;
	node->specular = 0.9;
	node->shininess = 200.0;
	node->reflective = 0.0;
	node->ambient = 0.0;
	node->checker = 0;
	node->x_scale = 1.0;
	node->y_scale = 1.0;
	node->z_scale = 1.0;
	node->x_rot = 0.0;
	node->y_rot = 0.0;
	node->z_rot = 0.0;
}

void	parse_mat(t_line *node, char *mat, t_data *data)
{
	double	value;

	if (!is_double(mat + 2))
		rt_error(WR_FORMAT_OP, data);
	value = rt_atod(mat + 2, data);
	if (!ft_strncmp(mat, "df", 2))
		node->diffuse = value;
	if (!ft_strncmp(mat, "sc", 2))
		node->specular = value;
	if (!ft_strncmp(mat, "re", 2))
		node->reflective = value;
	if (!ft_strncmp(mat, "sh", 2))
		node->shininess = value;
	if (!ft_strncmp(mat, "am", 2))
		node->ambient = value;
	if ((!ft_strncmp(mat, "df", 2) || !ft_strncmp(mat, "sc", 2)
			|| !ft_strncmp(mat, "re", 2) || !ft_strncmp(mat, "am", 2))
		&& (value < 0.0 || value > 1.0))
		rt_error("Diffuse/specular/reflective/ambient value: 0.0 to 1.0", data);
	if (!ft_strncmp(mat, "sh", 2) && (value < 1.0 || value > 200.0))
		rt_error("Shininess value must be between 1.0 and 200.0", data);
}

void	parse_scale(t_line *node, char *scale, t_data *data)
{
	t_vect	s;

	s = get_vect(scale + 1, DBL, data);
	if (s.x <= EPSILON || s.y <= EPSILON || s.z <= EPSILON)
		rt_error("Scaling value too low", data);
	node->x_scale = s.x;
	node->y_scale = s.y;
	node->z_scale = s.z;
}

void	parse_rot(t_line *node, char *rot, t_data *data)
{
	t_vect	r;

	r = get_vect(rot + 1, DBL, data);
	node->x_rot = r.x;
	node->y_rot = r.y;
	node->z_rot = r.z;
}

void	parse_options(t_line *node, char **configs, t_data *data)
{
	size_t	i;

	i = 0;
	while (configs[i])
	{
		if (!ft_strncmp(configs[i], "df", 2) || !ft_strncmp(configs[i], "sc", 2)
			|| !ft_strncmp(configs[i], "sh", 2)
			|| !ft_strncmp(configs[i], "re", 2)
			|| !ft_strncmp(configs[i], "am", 2))
			parse_mat(node, configs[i], data);
		else if (!ft_strncmp(configs[i], "ch", 3))
			node->checker = 1;
		else if (!ft_strncmp(configs[i], "S", 1))
			parse_scale(node, configs[i], data);
		else if (!ft_strncmp(configs[i], "R", 1))
			parse_rot(node, configs[i], data);
		else
			rt_error("Unrecognized shape option", data);
		i++;
	}
}
