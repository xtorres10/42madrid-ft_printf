/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtorres- <xtorres-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:05:54 by xtorres-          #+#    #+#             */
/*   Updated: 2022/05/02 16:06:01 by xtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printnbr(int num, char letter)
{
	if (num <= 9)
		ft_printchar(num + 48);
	else if (letter == 'x')
		ft_printchar('a' + num - 10);
	else if (letter == 'X')
		ft_printchar('A' + num - 10);
	return (1);
}

static int	ft_sizenumb(int nb, int base)
{
	int	s;

	s = 1;
	if (nb == -2147483648)
	{
		nb = 147483648;
		s += 2;
	}
	if (nb < 0)
	{
		nb *= -1;
		s++;
	}
	if (nb >= base)
		return (s + ft_sizenumb(nb / base, base));
	else
		return (s);
}

int	ft_putnbr(int n)
{
	long int	nb;
	int			result;

	nb = n;
	result = ft_sizenumb(nb, 10);
	if (nb >= -2147483648 && nb <= 2147483647)
	{
		if (nb < 0)
		{
			ft_printchar('-');
			nb *= -1;
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			nb = nb % 10;
		}
		if (nb < 10)
			ft_printchar(nb + '0');
	}
	return (result);
}

int	ft_print_ux(size_t num, int base, char f)
{
	int	result;

	result = 1;
	if (num >= (size_t)base)
	{
		result += ft_print_ux(num / base, base, f);
		ft_printnbr(num % base, f);
	}
	else
		ft_printnbr(num, f);
	return (result);
}
/*
int main()
{
	//printf("%d", 3735929054u % 10);
	//printf("%d", ft_putnbr_fd(2147483648, 1));
	printf(" %d\n", ft_print_ux(3735929054u, 16, 'x'));
}*/