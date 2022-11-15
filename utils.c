/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtorres- <xtorres-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:40:09 by xtorres-          #+#    #+#             */
/*   Updated: 2022/05/16 21:40:11 by xtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i += ft_printchar(s[i]);
	}
	else
		i = ft_printstr("(null)");
	return (i);
}
/*
int main()
{
	char	*s;

	s = "\t";
	printf("%d", ft_printchar_fd(s, 1));
	//printf("%d", printf("n: %d", 99));∫
}*/
