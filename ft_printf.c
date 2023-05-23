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

int	ft_variables(char c, va_list arg, int *count)
{
	if (c == 'c')
		return (ft_putchr_pf(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstr_pf(va_arg(arg, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_pf(va_arg(arg, int), count));
	if (c == 'p')
	{
		write(1, "0x", 2);
		return (ft_putptr_pf(va_arg(arg, unsigned long),
				"0123456789abcdef", 1));
	}
	if (c == 'x')
		return (ft_puthex(va_arg(arg, unsigned long long), "0123456789abcdef", count));
	if (c == 'X')
		return (ft_puthex(va_arg(arg, unsigned long long), "0123456789ABCDEF", count));
	if (c == '%')
		return (ft_putchr_pf('%'));
	if (c == 'u')
		return (ft_putun(va_arg(arg, unsigned long), count));
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
				count += ft_variables(s[i], arg, &count);
			}
			else
			{
				count += write(1, &s[i], 1);
			}
			i++;
		}

	}
	va_end(arg);
	printf("\nco:%u\n", count);

	return (count);
}
int	main(void)
{
	char c = '%';
	char *s = "soy una string";
	int d = 2432;
	void *ptr = "ke pasa";

//	ft_printf("%d%d%d", -56410000, 654, 1);
//	printf("\noriginal: %d", -12345);

//	ft_printf("%c", c);
//	printf("\noriginal:%c\n", c);
	
//	ft_printf("soy una string: %s", s);
///	printf("\noriginal:%s\n", s);

//	ft_printf("soy un digito: %d", d);
//	printf("\noriginal:%d\n", d);

//	ft_printf("soy un puntero: %p", ptr);
//	printf("\noriginal:%p\n", ptr);

//	ft_printf("%X%X%X", 100, 5442, -12321);
//	printf("%X%X%X", 100, 5442, -12321);

//	ft_printf("%s %d %p %% %x", "bonjour ", 42, &free, 42);
//	printf("%s %d %p %% %x", "bonjour ", 42, &free, 42);

//	ft_printf("%lX", 2147483647);
//	printf("%lX", 2147483647);


// ft_printf("b%p", 4294967295);
//	ft_printf("soy un porcentaje: %%");
//	printf("\noriginal: %%\n");
	return (0);
}
