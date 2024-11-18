/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:57:37 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/17 00:27:32 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	free_list(t_data *data)
{
	t_line	*temp;

	while (data->line_lst)
	{
		temp = data->line_lst;
		data->line_lst = data->line_lst->next;
		free(temp);
	}
}

int	validate_list(t_data *data)
{
	t_line	*temp;
	int		c;
	int		a;
	int		l;

	temp = data->line_lst;
	c = 0;
	a = 0;
	l = 0;
	while (temp)
	{
		if (temp->type == AMBIENT)
			a++;
		if (temp->type == CAMERA)
			c++;
		if (temp->type == LIGHT)
			l++;
		temp = temp->next;
	}
	if (a > 1 || a < 1 || c > 1 || c < 1 || l < 1)
		rt_error(WR_FORMAT_CNT, data);
	return (0);
}

void	populate_node(t_line *node, char **configs, t_data *data)
{
	default_options(node);
	if (node->type == LIGHT)
		parse_light(node, configs, data);
	else if (node->type == SPHERE)
		parse_sphere(node, configs, data);
	else if (node->type == PLANE)
		parse_plane(node, configs, data);
	else if (node->type == CYLINDER)
		parse_cylinder(node, configs, data);
	else if (node->type == CONE)
		parse_cone(node, configs, data);
	else if (node->type == CUBE)
		parse_cube(node, configs, data);
	else if (node->type == CAMERA)
		parse_camera(node, configs, data);
	else if (node->type == AMBIENT)
		parse_ambient(node, configs, data);
}

void	populate_list(t_data *data, char *line)
{
	char	**configs;
	t_line	*new;

	if (check_empty_line(line))
		return ;
	new = rt_lstnew(data, line);
	if (!new)
		rt_error(MEMORY_FAIL, data);
	rt_lstadd_back(&data->line_lst, new);
	if (!check_object(new))
		rt_error(WR_FORMAT, data);
	if (new->line[ft_strlen(new->line) - 1] == '\n')
		new->line[ft_strlen(new->line) - 1] = ' ';
	configs = rt_split(new->line);
	if (!configs)
		rt_error(MEMORY_FAIL, data);
	populate_node(new, configs, data);
	freearray(configs);
}

int	process_file(t_data *data)
{
	char	*line;

	data->rt_scene = -1;
	data->line_lst = NULL;
	check_file_ext(data);
	data->rt_scene = open(data->av[1], O_RDONLY);
	if (data->rt_scene < 0)
		rt_error(FILE_ERROR, data);
	line = get_next_line(data->rt_scene);
	while (line)
	{
		populate_list(data, line);
		free(line);
		line = get_next_line(data->rt_scene);
	}
	close(data->rt_scene);
	data->rt_scene = -1;
	validate_list(data);
	populate_scene(data);
	free_list(data);
	return (0);
}
