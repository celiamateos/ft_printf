/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:33:29 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/21 21:46:40 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptr_pf(unsigned long nbr, char *hex, int count)
{
	if (nbr >= 0)
	{	
		if (nbr <= 15)
			count += write(1, &hex[nbr], 1);
		else
		{
			count += ft_putptr_pf(nbr / 16, hex, count);
			nbr = nbr % 16;
			write(1, &hex[nbr], 1);
		}
	}
	return (count);
}
