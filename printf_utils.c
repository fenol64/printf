/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnascime <fnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:20:21 by fnascime          #+#    #+#             */
/*   Updated: 2023/11/06 14:27:44 by fnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_putchar(int c)
{
        write(1, &c, 1);
        return (1);
}

int     ft_putstr(char *s)
{
        int     i;

        i = -1;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[++i])
		if (!s)
			return (ft_putstr("(null)"));
		else
                	write(1, &s[i], 1);
        return (i);
}

int    ft_putnbr_base(int nbr, int base, int is_upper)
{
        int     bytes_printed;
        char    *base_str;

        bytes_printed = 0;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
        if (is_upper)
                base_str = "0123456789ABCDEF";
        else
                base_str = "0123456789abcdef";
        if (nbr < 0)
        {
                bytes_printed += ft_putchar('-');
                nbr *= -1;
        }
        if (nbr >= base)
                bytes_printed += ft_putnbr_base(nbr / base, base, is_upper);
        bytes_printed += ft_putchar(base_str[nbr % base]);
        return (bytes_printed);
}

int ft_putnbr_u_base(unsigned int nbr, unsigned int base, int is_upper)
{
        int bytes_printed;
        char *base_str;

        bytes_printed = 0;
        if (is_upper)
                base_str = "0123456789ABCDEF";
        else
                base_str = "0123456789abcdef";
        if (nbr < 0)
        {
                bytes_printed += ft_putchar('-');
                nbr *= -1;
        }
        if (nbr >= base)
                bytes_printed += ft_putnbr_base(nbr / base, base, is_upper);
        bytes_printed += ft_putchar(base_str[nbr % base]);
        return (bytes_printed);
}

int ft_putptr(unsigned long int ptr, int print_ox)
{
        int     bytes_printed;

	if (ptr == (unsigned long int)NULL)
		return (ft_putstr("(nil)"));
        bytes_printed = 0;	
	if (print_ox)
		bytes_printed = ft_putstr("0x");
        if (ptr >= 16)
                bytes_printed += ft_putptr(ptr / 16, 0);
        bytes_printed += ft_putnbr_base(ptr % 16, 16, 0);
        return (bytes_printed);
}
