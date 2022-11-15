/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtorres- <xtorres-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:29:41 by xtorres-          #+#    #+#             */
/*   Updated: 2022/05/07 13:29:52 by xtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list argms, char f);

int	ft_printf(char const *str, ...)
{
	va_list	argms;
	int		result;

	result = 0;
	va_start(argms, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			result += ft_format(argms, *str);
		}
		else
			result += ft_printchar(*str);
		str++;
	}
	va_end(argms);
	return (result);
}

static int	ft_format(va_list argms, char f)
{
	int	result;

	result = 0;
	if (f == '%')
		result = ft_printchar('%');
	else if (f == 'c')
		result = ft_printchar(va_arg(argms, int));
	else if (f == 's')
		result = ft_printstr(va_arg(argms, char *));
	else if (f == 'p')
	{
		result += ft_printstr("0x");
		result += ft_print_ux(va_arg(argms, size_t), 16, 'x');
	}
	else if (f == 'd' || f == 'i')
		result = ft_putnbr(va_arg(argms, int));
	else if (f == 'u')
		result = ft_print_ux(va_arg(argms, unsigned int), 10, f);
	else if (f == 'x' || f == 'X')
		result = ft_print_ux(va_arg(argms, unsigned int), 16, f);
	return (result);
}
/*
int	main(void)
{
	int b;
	char *s;

	s = "paquita";

	b = 10;
	ft_printf("%d\n", ft_printf("%x", 3735929054u));
	printf("%d\n", printf("%x", 3735929054u));
}
*/