/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:53:19 by ppolinta          #+#    #+#             */
/*   Updated: 2024/11/17 01:24:00 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

static inline void	print_manual_ext(void)
{
	printf(BOLD GREEN"Camera Mode\n"RESET
		"Press "BOLD"C"RESET" to enter Camera Mode.\n"
		"Press "BOLD"W/A/S/D/space/Lshift"RESET" to move the camera.\n"
		"Press "BOLD"up/down/left/right"RESET
		" to change the camera's direction.\n"
		"Press "BOLD"I/O/P"RESET
		" to change the RGB values of the last created light.\n"
		"If there are no lights, it will change the ambient light.\n"
		"Press "BOLD"</>"RESET" to change the FOV.\n\n"
		BOLD BLUE"Object Mode\n"RESET
		"Left click on an object to select it and enter Object Mode.\n"
		"Press "BOLD"X"RESET" to delete the object.\n"
		"Press "BOLD"W/A/S/D/space/Lshift"RESET" to move the object.\n"
		"Press "BOLD"up/down/left/right/Q/E"RESET" to rotate the object.\n"
		"Press "BOLD"I/O/P"RESET" to change the RGB values of the object.\n"
		"Press "BOLD"</>"RESET" to scale the object.\n"
		"Press "BOLD"H/J/K"RESET" to upscale the object in XYZ.\n"
		"Press "BOLD"B/N/M"RESET" to downscale the object in XYZ.\n"
		"Press "BOLD"[/]"RESET" to add checkers to the object.\n"
		"Press "BOLD":"RESET" to change the object's reflectiveness.\n"
		"Press "BOLD"T"RESET" to change the object's specularity.\n"
		"Press "BOLD"Y"RESET" to change the object's diffusion.\n"
		"Press "BOLD"U"RESET" to change the object's shininess.\n");
}

void	print_manual(void)
{
	printf(RESET BOLD YELLOW"\nCONTROL MANUAL\n\n"RESET
		BOLD RED"General Controls\n"RESET
		"Press "BOLD"esc"RESET" to quit miniRT.\n"
		"Press "BOLD"R"RESET" to reset the scene.\n"
		"Press "BOLD"0"RESET" to toggle Superfast rendering.\n"
		"Press "BOLD"0"RESET" to toggle LERP rendering.\n"
		"Press "BOLD"8"RESET" to toggle Shadows rendering.\n"
		"Press "BOLD"9"RESET" to toggle Reflections rendering.\n"
		"Press "BOLD"Z"RESET" to add a new object.\n"
		"Press "BOLD"1"RESET" to add a new point light.\n"
		"Press "BOLD"2"RESET" to remove all point lights.\n"
		"Press "BOLD"L"RESET" to adjust ambient light strength.\n"
		"Press "BOLD"F"RESET" to toggle flashlight.\n"
		"Press "BOLD"+/-"RESET
		" to adjust movement speed of the camera/objects.\n\n");
	print_manual_ext();
}
