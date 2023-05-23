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


int	ft_putnbr_pf(long nbr, int *count)
{
	if (nbr < 0)
	{
		*count += ft_putchr_pf('-');
		nbr = nbr * (-1);
	}
	if (nbr / 10 != 0)
			ft_putnbr_pf(nbr / 10, count);
	*count += ft_putchr_pf((nbr % 10) + '0');
	printf("count%u", *count);
	return (0);
}
/*
int	ft_putnbr_pf(long nbr, int count)
{
	int	temp;

	temp = 0;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		write (1, "-", 1);
		count++;
	}
		if (nbr >= 0)
	{
		if (nbr < 10)
		{
			nbr = nbr + '0';
			write (1, &nbr, 1);
		}
		else if (nbr)
		while (nbr >= 0 && nbr)
		{
			count++;
			nbr = nbr / 10;
			temp = nbr % 10 + '0';
			write (1, &temp, 1);
			if (nbr == 0)
				break ;
		}
	}
	printf("count:%i", count);
	return count;	
}*/