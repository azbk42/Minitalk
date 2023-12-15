/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:39:12 by azbk              #+#    #+#             */
/*   Updated: 2023/11/13 12:56:53 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(const char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(const char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	while (str[i])
		ft_putchar(str[i++], count);
}

void	print_hexa(int *count, unsigned int long nbr, char letter, unsigned int base)
{
	char	*hexa_min;
	char	*hexa_maj;
	char	*decimal;

	hexa_min = "0123456789abcdef";
	hexa_maj = "0123456789ABCDEF";
	decimal = "0123456789";
	if (nbr >= base)
	{
		print_hexa(count, nbr / base, letter, base);
		print_hexa(count, nbr % base, letter, base);
	}
	else if (letter == 'x')
		ft_putchar(hexa_min[nbr], count);
	else if (letter == 'X')
		ft_putchar(hexa_maj[nbr], count);
	else
		ft_putchar(decimal[nbr], count);
}

void	ft_putnbr(int nb, int *count)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, count);
		ft_putnbr(nbr % 10, count);
	}
	else
		ft_putchar(nbr + '0', count);
}

void	print_adress(void *add, int *count)
{
	unsigned long int	nbr;

	nbr = 0;
	if (add == NULL)
		ft_putstr("(nil)", count);
	else
	{
		nbr = (unsigned long int)add;
		ft_putstr("0x", count);
		print_hexa(count, nbr, 'x', 16);
	}
}
