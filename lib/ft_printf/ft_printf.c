/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:44:38 by azbk              #+#    #+#             */
/*   Updated: 2023/11/13 12:54:32 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_format(int *count, char format, va_list args)
{
	if (format == '%')
		ft_putchar('%', count);
	else if (format == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format == 'x' || format == 'X')
		print_hexa(count, va_arg(args, unsigned int), format, 16);
	else if (format == 'i' || format == 'd')
		ft_putnbr(va_arg(args, int), count);
	else if (format == 'u')
		print_hexa(count, va_arg(args, unsigned int), format, 10);
	else if (format == 'p')
		print_adress(va_arg(args, void *), count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			parsing_format(&count, format[i], args);
			i++;
		}
		else
			ft_putchar(format[i++], &count);
	}
	va_end(args);
	return (count);
}
