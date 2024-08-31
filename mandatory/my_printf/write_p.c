/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:56:42 by pzau              #+#    #+#             */
/*   Updated: 2024/05/25 07:20:36 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_i(int n);

void	priting(char str)
{
	write(1, &str, 1);
}

void	write_p(void *ptr)
{
	unsigned long	n;
	const char		*hex_digits;

	n = (unsigned long)ptr;
	hex_digits = "0123456789abcdef";
	if (n >= 16)
		write_p((void *)(n / 16));
	priting(hex_digits[n % 16]);
}

void	print_pointer(void *str)
{
	unsigned long	addr;

	addr = (unsigned long)str;
	write(1, "0x", 2);
	if (addr == 0)
		write(1, "0", 1);
	else
		write_p(str);
}

void	less(int num_digits, int *n)
{
	int		digit;
	int		i;
	char	digit_char;

	digit = *n;
	i = 0;
	while (i < num_digits - 1)
	{
		digit /= 10;
		i++;
	}
	digit_char = digit % 10 + '0';
	write(1, &digit_char, 1);
	num_digits--;
}

void	write_i(int n)
{
	int	is_negative;
	int	num_digits;
	int	temp;

	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	num_digits = 0;
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		num_digits++;
	}
	if (is_negative)
		write(1, "-", 1);
	while (num_digits > 0)
	{
		less(num_digits, &n);
		num_digits--;
	}
}
