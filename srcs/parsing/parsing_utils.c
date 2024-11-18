/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:56:49 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/16 17:07:13 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

char	check_empty_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && is_whitespace(line[i]))
		i++;
	if (!line[i] || line[i] == '\n' || !ft_strncmp(line, "", 1))
		return (1);
	return (0);
}

int	skip_whitespaces(t_line *node, int i)
{
	while (node->line[i] && is_whitespace(node->line[i]))
		i++;
	return (i);
}

char	check_object(t_line *node)
{
	int	i;

	i = skip_whitespaces(node, 0);
	if (!ft_strncmp(node->line + i, "A ", 2))
		node->type = AMBIENT;
	else if (!ft_strncmp(node->line + i, "C ", 2))
		node->type = CAMERA;
	else if (!ft_strncmp(node->line + i, "L ", 2))
		node->type = LIGHT;
	else if (!ft_strncmp(node->line + i, "sp ", 3))
		node->type = SPHERE;
	else if (!ft_strncmp(node->line + i, "pl ", 3))
		node->type = PLANE;
	else if (!ft_strncmp(node->line + i, "cy ", 3))
		node->type = CYLINDER;
	else if (!ft_strncmp(node->line + i, "co ", 3))
		node->type = CONE;
	else if (!ft_strncmp(node->line + i, "cu ", 3))
		node->type = CUBE;
	else if (!ft_strncmp(node->line, "#", 1))
		node->type = SKIP;
	else
		return (0);
	return (1);
}

int	array_len(char **array)
{
	int	i;

	i = 0;
	if (!array || !array[i])
		return (0);
	while (array[i])
		i++;
	return (i);
}
