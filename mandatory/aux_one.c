/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:27:39 by pzau              #+#    #+#             */
/*   Updated: 2024/08/19 17:58:09 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	*allocate_word(const char *start, int length)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (length + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < length)
	{
		word[i] = start[i];
		i++;
	}
	word[length] = '\0';
	return (word);
}

char	**allocate_matrix(int words)
{
	char	**matrix;

	matrix = malloc(sizeof(char *) * (words + 1));
	if (!matrix)
		return (NULL);
	matrix[words] = NULL;
	return (matrix);
}

void	fill_matrix(char **matrix, char *s, int words)
{
	int	y;
	int	start;

	y = 0;
	while (*s)
	{
		while (*s && delimiter(*s))
			s++;
		if (*s && !delimiter(*s))
		{
			start = 0;
			while (s[start] && !delimiter(s[start]))
				start++;
			matrix[y] = allocate_word(s, start);
			if (!matrix[y])
			{
				free_split(matrix);
				return ;
			}
			y++;
			s += start;
		}
	}
}

char	**ft_split(char *s)
{
	char	**matrix;
	int		words;

	words = count_words(s);
	matrix = allocate_matrix(words);
	if (!matrix)
		return (NULL);
	fill_matrix(matrix, s, words);
	return (matrix);
}
