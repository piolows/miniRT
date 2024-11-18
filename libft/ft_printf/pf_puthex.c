/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:43:52 by ppolinta          #+#    #+#             */
/*   Updated: 2024/06/28 16:54:31 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_puthex(unsigned long n, int cs, int fd)
{
	int		x;
	char	*base;

	x = 0;
	if (!cs)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n > 15)
		x += pf_puthex(n / 16, cs, fd);
	x += pf_putchar(base[n % 16], fd);
	return (x);
}
