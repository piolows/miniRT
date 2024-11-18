/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:13:42 by ppolinta          #+#    #+#             */
/*   Updated: 2024/06/28 16:57:01 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define BOLD    "\x1b[1m"
# define RESET   "\x1b[0m"

int		ft_printf(const char *format, ...);
int		debug(const char *format, ...);
int		pf_putchar(char c, int fd);
int		pf_putint(int n, int fd);
int		pf_putuint(unsigned int n, int fd);
int		pf_putstr(char *s, int fd);
int		pf_putmem(void *mem, int fd);
int		pf_puthex(unsigned long n, int cs, int fd);

#endif