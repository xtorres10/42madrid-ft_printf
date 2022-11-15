/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtorres- <xtorres-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:21:37 by xtorres-          #+#    #+#             */
/*   Updated: 2022/05/16 22:21:40 by xtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Imports standar arguments for variadicts functions
# include <stdarg.h>
// Imports standard unix write
# include <unistd.h>
// Imports standar types definitions ie: size_t
# include <stddef.h>

int	ft_printchar(char c);
int	ft_printstr(char *s);
int	ft_putnbr(int n);
int	ft_print_ux(size_t num, int base, char f);
int	ft_printf(char const *str, ...);

#endif
