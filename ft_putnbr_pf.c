/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:16:38 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/22 18:42:46 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_pf(long nbr, int count)
{
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		count += write (1, "-", 1);

	}
	if (nbr >= 0)
	{
		if (nbr < 10)
		{
			nbr = nbr + '0';
			write (1, &nbr, 1);
		}
		else
		{
			count++;
			ft_putnbr_pf(nbr / 10, count);
			nbr = nbr % 10 + '0';
			write (1, &nbr, 1);
		}
	}
//			printf("count:%i", count);
	return (count);
}
