/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agodeanu <agodeanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:57:30 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/16 22:26:20 by agodeanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_material	create_default_material(void)
{
	t_material	result;

	result.ambient = 0.0;
	result.diffuse = 0.9;
	result.specular = 0.9;
	result.shininess = 200.0;
	result.reflective = 0.0;
	result.pattern.type = SOLID;
	result.colour = get_rgb(0x00FFFFFF);
	result.pattern.a = result.colour;
	result.pattern.b = get_rgb(0x00FFFFFF);
	result.pattern.height = 2;
	result.pattern.width = 2;
	return (result);
}
