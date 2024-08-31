/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:03:05 by pzau              #+#    #+#             */
/*   Updated: 2024/08/19 17:31:59 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_words(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && delimiter(*s))
			s++;
		if (*s && !delimiter(*s))
		{
			count++;
			while (*s && !delimiter(*s))
				s++;
		}
	}
	return (count);
}

int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	free_split(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
