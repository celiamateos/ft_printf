/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:02:58 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/22 18:42:58 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_variables(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchr_pf(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstr_pf(va_arg(arg, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_pf(va_arg(arg, int), 1));
	if (c == 'p')
	{
		write(1, "0x", 2);
		return (ft_putptr_pf(va_arg(arg, unsigned long),
				"0123456789abcdef", 1));
	}
	if (c == 'x')
		return (ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef", 0));
	if (c == 'X')
		return (ft_puthex(va_arg(arg, unsigned int), "0123456789ABCDEF", 0));
	if (c == '%')
		return (ft_putchr_pf('%'));
	if (c == 'u')
		return (ft_putun(va_arg(arg, unsigned long), 0));
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, s);
	if (s)
	{
		while (s[i])
		{
			if (s[i] == '%')
			{
				i++;
				count += ft_variables(s[i], arg);
			}
			else
			{
				count += write(1, &s[i], 1);
			}
			i++;
		}

	}
	va_end(arg);
//	printf("co:%i", count);

	return (count);
}/*
int	main(void)
{
	char c = '%';
	char *s = "soy una string";
	int d = 2432;
	void *ptr = "ke pasa";

	ft_printf("%d", -10000);
	printf("\noriginal: %d", -10000);

//	ft_printf("%c", c);
//	printf("\noriginal:%c\n", c);
	
//	ft_printf("soy una string: %s", s);
///	printf("\noriginal:%s\n", s);

//	ft_printf("soy un digito: %d", d);
//	printf("\noriginal:%d\n", d);

//	ft_printf("soy un puntero: %p", ptr);
//	printf("\noriginal:%p\n", ptr);

//	ft_printf("soy un hexadecimal: %X", d);
//	printf("\noriginal: %X\n", d);

//	ft_printf("soy un porcentaje: %%");
//	printf("\noriginal: %%\n");
	return (0);
}*/
