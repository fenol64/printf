/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:52:19 by fnascime          #+#    #+#             */
/*   Updated: 2023/11/06 14:28:01 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int ft_putchar(int c);
int ft_putstr(char *s);
int ft_putnbr_base(int nbr, int base, int is_uppercase);
int ft_putnbr_u_base(unsigned int nbr, unsigned int base, int is_uppercase);
int ft_putptr(unsigned long int ptr, int print_ox);

int treat_current_arg(char c, va_list argument);
int ft_printf(const char *fmt, ...);


#endif
