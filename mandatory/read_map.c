/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:58:53 by pzau              #+#    #+#             */
/*   Updated: 2024/08/23 18:06:05 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*append_to_content(char *content, char *buffer)
{
	char	*new_content;
	char	*temp;

	temp = content;
	if (content == NULL)
		new_content = ft_strdup(buffer);
	else
		new_content = ft_strcat(content, buffer);
	if (temp)
		free(temp);
	return (new_content);
}

char	*read_file_content(const char *filename)
{
	char	buffer[1025];
	char	*content;
	char	*temp;
	int		bytes_read;
	int		fd;

	content = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		fd_last();
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		content = append_to_content(content, buffer);
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	}
	close(fd);
	if (bytes_read < 0 || content == NULL)
	{
		free(content);
		exit(1);
	}
	return (content);
}

char	**print_map(const char *filename)
{
	char	*content;
	char	**map;

	content = read_file_content(filename);
	map = ft_split(content);
	free(content);
	return (map);
}

void	disp_file(int fd, t_dimensoes *dim)
{
	char	buffer;
	int		flag;
	int		w;
	int		h;

	w = 0;
	h = 0;
	flag = 0;
	dim->height_screen = 0;
	dim->width_screen = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		if (buffer != '\n')
		{
			if (!flag)
				w++;
		}
		if (buffer == '\n')
		{
			flag = 1;
			h++;
		}
	}
	dim->height_screen = h;
	dim->width_screen = w;
}

void	dimention(char *fdf, t_dimensoes *dim)
{
	int	fd;

	fd = open(fdf, O_RDONLY);
	if (fd == -1)
		ft_printf("  Erro ao abrir arquivo dimention\n\n");
	disp_file(fd, dim);
	close(fd);
}
