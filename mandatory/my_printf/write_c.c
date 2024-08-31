/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:26:16 by pzau              #+#    #+#             */
/*   Updated: 2024/08/10 10:52:22 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_c(char word)
{
	write(1, &word, 1);
}

void	less_x(unsigned int n)
{
	const char	*hex_digits;
	char		digit_char;

	hex_digits = "0123456789abcdef";
	if (n >= 16)
		less_x(n / 16);
	digit_char = hex_digits[n % 16];
	write(1, &digit_char, 1);
}

void	write_x(unsigned int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	less_x(n);
}

void	less_u(unsigned int n)
{
	char	digit_char;

	if (n >= 10)
		less_u(n / 10);
	digit_char = n % 10 + '0';
	write(1, &digit_char, 1);
}

void	write_u(unsigned int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	less_u(n);
}
