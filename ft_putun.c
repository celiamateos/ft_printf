/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:37:13 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/21 21:46:47 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putun(unsigned long nbr, int count)
{
	if (nbr < 10)
	{
		nbr = nbr + '0';
		write (1, &nbr, 1);
		count++;
	}
	else
	{
		count += ft_putun(nbr / 10, count);
		nbr = nbr % 10 + '0';
		write (1, &nbr, 1);
	}
	return (count);
}
