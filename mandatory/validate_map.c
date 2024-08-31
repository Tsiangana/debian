/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:07:27 by pzau              #+#    #+#             */
/*   Updated: 2024/08/21 01:53:26 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	validate_player(char **map, t_dimensoes *dim, t_vars *vars)
{
	int	x;
	int	y;
	int	player_count;

	player_count = 0;
	y = 0;
	while (y < dim->height_screen)
	{
		x = 0;
		while (x < dim->width_screen)
		{
			if (map[y][x] == 'P')
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1)
	{
		ft_printf("  Mapa inválido, apenas é permitido um P\n\n");
		free_split(vars->map);
		free_split(vars->map_copy);
		exit(1);
	}
}

void	validate_exit(char **map, t_dimensoes *dim, t_vars *vars)
{
	int	x;
	int	y;
	int	exited;

	exited = 0;
	y = 0;
	while (y < dim->height_screen)
	{
		x = 0;
		while (x < dim->width_screen)
		{
			if (map[y][x] == 'E')
				exited++;
			x++;
		}
		y++;
	}
	if (exited != 1)
	{
		ft_printf("  Mapa inválido, apenas é permitido um E\n\n");
		free_split(vars->map);
		free_split(vars->map_copy);
		exit(1);
	}
}

int	all_things(char **map, t_dimensoes *dim, t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < dim->height_screen)
	{
		x = 0;
		while (x < dim->width_screen)
		{
			if (map[y][x] != 'E' && map[y][x] != '1'
				&& map[y][x] != '0' && map[y][x] != 'C'
				&& map[y][x] != 'P')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	validate_colector(char **map, t_dimensoes *dim, t_vars *vars)
{
	int	x;
	int	y;
	int	colector;

	colector = 0;
	y = 0;
	while (y < dim->height_screen)
	{
		x = 0;
		while (x < dim->width_screen)
		{
			if (map[y][x] == 'C')
				colector++;
			x++;
		}
		y++;
	}
	if (colector < 1)
	{
		ft_printf("  Mapa inválido, coletores indisponíveis\n\n");
		free_split(vars->map);
		free_split(vars->map_copy);
		exit(1);
	}
}

void	validate_rectangle(char **map, t_dimensoes *dim, t_vars *vars)
{
	int	line_length;
	int	y;

	if (!map || !map[0])
	{
		ft_printf("  Erro: Mapa inválido ou vazio\n\n");
		free_split(vars->map);
		free_split(vars->map_copy);
		exit(1);
	}
	line_length = ft_strlen(map[0]);
	y = 1;
	while (map[y] != NULL)
	{
		if ((int)ft_strlen(map[y]) != line_length)
		{
			ft_printf("  Mapa inválido: Não é um retângulo\n\n");
			free_split(vars->map);
			free_split(vars->map_copy);
			exit(1);
		}
		y++;
	}
}
