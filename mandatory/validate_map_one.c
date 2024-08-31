/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:51:34 by pzau              #+#    #+#             */
/*   Updated: 2024/08/24 11:30:06 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_map_closed(char **map, int height, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	finding_start_point(char **matrix, t_vars *vars, char c)
{
	int	k;
	int	x;

	k = 0;
	while (matrix[k])
	{
		x = 0;
		while (matrix[k][x])
		{
			if (matrix[k][x] == c)
			{
				vars->start_point.x = x;
				vars->start_point.y = k;
				return ;
			}
			x++;
		}
		k++;
	}
}

void	sending_to_flood_fill(t_vars *vars)
{
	finding_start_point(vars->map_copy, vars, 'P');
	flood_fill(vars->start_point.x, vars->start_point.y, vars);
}

void	finish_that_stupid_verifications(t_vars *vars)
{
	if (!is_map_closed(vars->map,
			vars->dim.height_screen, vars->dim.width_screen))
	{
		ft_printf("  Mapa nao fechado\n\n");
		free_split(vars->map_copy);
		free_split(vars->map);
		exit(1);
	}
	sending_to_flood_fill(vars);
	func_close(vars);
	finding_start_point(vars->map_copy, vars, 'E');
	flood(vars->start_point.x, vars->start_point.y, vars);
	if (strchr_on_matrix(vars->map_copy, 'E') == 1)
	{
		ft_printf(" Mapa invalido\n\n");
		free_split(vars->map_copy);
		free_split(vars->map);
		exit(1);
	}
}

void	func_close(t_vars *vars)
{
	if (strchr_on_matrix(vars->map_copy, 'C') == 1)
	{
		ft_printf("  Mapa invalido\n\n");
		free_split(vars->map_copy);
		free_split(vars->map);
		exit(1);
	}
	if (strchr_on_matrix(vars->map_copy, 'P') == 1)
	{
		ft_printf("  Mapa invalido\n\n");
		free_split(vars->map_copy);
		free_split(vars->map);
		exit(1);
	}
}
