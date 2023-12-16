/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:45:53 by emauduit          #+#    #+#             */
/*   Updated: 2023/12/16 15:55:15 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include "libft.h"
# include "ft_printf.h"

// Client
void	ft_send_char(int pid, unsigned char c);
void	ft_send_string(int pid, const char *str);
void	sigclient(int signum);

#endif