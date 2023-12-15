/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:44:44 by azbk              #+#    #+#             */
/*   Updated: 2023/11/13 12:57:20 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putstr(const char *str, int *count);
void	ft_putchar(const char c, int *count);
void	print_hexa(int *count, unsigned int long nbr, char letter, unsigned int base);
void	ft_putnbr(int nb, int *count);
void	print_adress(void *add, int *count);

#endif