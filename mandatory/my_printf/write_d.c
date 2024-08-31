/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:18:38 by pzau              #+#    #+#             */
/*   Updated: 2024/05/25 06:42:47 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_putstr(char *str)
{
	while (*str)
	{
		write_c(*str);
		str++;
	}
}

void	write_d(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write_c('-');
		n = -n;
	}
	if (n >= 10)
	{
		write_d(n / 10);
		write_d(n % 10);
	}
	else
	{
		write_c(n + '0');
	}
}

void	write_percent(void)
{
	char	percent;

	percent = '%';
	write(1, &percent, 1);
}
