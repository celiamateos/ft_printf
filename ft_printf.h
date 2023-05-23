/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:23:13 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/22 18:06:55 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(char const *s, ...);
int	ft_putchr_pf(char c);
int	ft_putstr_pf(char *s);
int	ft_putnbr_pf(long nbr,int *count);
int	ft_putptr_pf(unsigned long nbr, char *hex, int count);
int	ft_puthex(unsigned long long nbr, char *hex, int *count);
int	ft_putun(unsigned long nbr, int *count);

#endif
