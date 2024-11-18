/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:39:28 by ppolinta          #+#    #+#             */
/*   Updated: 2024/06/28 16:57:57 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putint(int n, int fd)
{
	int		count;

	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	count = 0;
	if (n < 0)
	{
		count += pf_putchar('-', 2);
		n *= -1;
	}
	if (n > 9)
		count += pf_putint(n / 10, fd);
	count += pf_putchar((n % 10) + '0', fd);
	return (count);
}
