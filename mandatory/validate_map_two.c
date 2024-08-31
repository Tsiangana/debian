/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 01:43:37 by pzau              #+#    #+#             */
/*   Updated: 2024/08/23 18:05:18 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	flood_fill(int x, int y, t_vars *vars)
{
	if (x < 0 || x >= vars->dim.width_screen
		|| y < 0 || y >= vars->dim.height_screen)
		return ;
	if (vars->map_copy[y][x] == 'V')
		return ;
	if (vars->map_copy[y][x] == '1' || vars->map_copy[y][x] == 'E')
		return ;
	vars->map_copy[y][x] = 'V';
	flood_fill(x + 1, y, vars);
	flood_fill(x - 1, y, vars);
	flood_fill(x, y + 1, vars);
	flood_fill(x, y - 1, vars);
}

void	flood(int x, int y, t_vars *vars)
{
	if (x < 0 || x >= vars->dim.width_screen
		|| y < 0 || y >= vars->dim.height_screen)
		return ;
	if (vars->map_copy[y][x] == 'F')
		return ;
	if (vars->map_copy[y][x] == '1')
		return ;
	vars->map_copy[y][x] = 'F';
	flood(x + 1, y, vars);
	flood(x - 1, y, vars);
	flood(x, y + 1, vars);
	flood(x, y - 1, vars);
}

int	strchr_on_matrix(char **matrix, char c)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (strchr(matrix[i], c))
			return (1);
		i++;
	}
	return (0);
}

void	fd_last(void)
{
	perror("Nothing");
	exit(1);
}
