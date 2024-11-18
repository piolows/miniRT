/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:44:24 by ppolinta          #+#    #+#             */
/*   Updated: 2024/06/28 16:54:50 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putmem(void *mem, int fd)
{
	long	n;
	int		count;

	count = 0;
	n = (unsigned long)mem;
	count += pf_putstr("0x", fd);
	count += pf_puthex(n, 0, fd);
	return (count);
}
