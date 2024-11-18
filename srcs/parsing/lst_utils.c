/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:03:00 by agodeanu          #+#    #+#             */
/*   Updated: 2024/11/05 14:47:05 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_line	*rt_lastnode(t_line *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_line	*rt_lstnew(t_data *data, char *line)
{
	t_line	*new_line;

	new_line = ft_calloc(1, sizeof(t_line));
	if (!new_line)
	{
		free(line);
		rt_error(MEMORY_FAIL, data);
	}
	new_line->line = line;
	return (new_line);
}

void	rt_lstadd_back(t_line **lst, t_line *node)
{
	t_line	*temp;

	if (!lst || !*lst)
	{
		*lst = node;
		node->next = NULL;
	}
	else
	{
		temp = rt_lastnode(*lst);
		temp->next = node;
		node->next = NULL;
	}
}
