/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:54:26 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/22 15:02:45 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex(unsigned long long nbr, char *hex, int *count)
{
	if (nbr / 16 != 0)
		ft_puthex(nbr / 16, hex, count);
	nbr = nbr % 16;
	*count += write (1, &hex[nbr], 1);
	return (0);
}
