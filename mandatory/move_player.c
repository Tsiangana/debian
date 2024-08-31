/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:49:00 by pzau              #+#    #+#             */
/*   Updated: 2024/08/21 02:16:20 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	find_player_position_init(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->dim.height_screen)
	{
		x = 0;
		while (x < vars->dim.width_screen)
		{
			if (vars->map[y][x] == 'P')
			{
				vars->x_pos = x;
				vars->y_pos = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_player_position(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	vars->steps = 0;
	vars->coletaveis = 0;
	while (y < vars->dim.height_screen)
	{
		x = 0;
		while (x < vars->dim.width_screen)
		{
			if (vars->map[y][x] == 'C')
				vars->coletaveis++;
			x++;
		}
		y++;
	}
	find_player_position_init(vars);
}

void	calculate_p(int keycode, int *new_x, int *new_y, t_vars *vars)
{
	if (keycode == 119)
	{
		*new_y -= 1;
		vars->steps++;
		ft_printf("  Steps: %d\n\n", vars->steps);
	}
	else if (keycode == 115)
	{
		*new_y += 1;
		vars->steps++;
		ft_printf("  Steps: %d\n\n", vars->steps);
	}
	else if (keycode == 97)
	{
		*new_x -= 1;
		vars->steps++;
		ft_printf("  Steps: %d\n\n", vars->steps);
	}
	else if (keycode == 100)
	{
		*new_x += 1;
		vars->steps++;
		ft_printf("  Steps: %d\n\n", vars->steps);
	}
}

void	process_map_interaction(t_vars *vars, int new_x, int new_y)
{
	if (vars->map[new_y][new_x] == 'C')
		vars->coletaveis--;
	if (vars->map[new_y][new_x] == 'M')
		close_x(vars);
	if (vars->map[new_y][new_x] == 'E' && vars->coletaveis == 0)
		close_x(vars);
	else if (vars->map[new_y][new_x] == 'E')
		ft_printf("  Ainda existem coletaveis no mapa\n\n");
	else
	{
		vars->map[vars->y_pos][vars->x_pos] = '0';
		vars->x_pos = new_x;
		vars->y_pos = new_y;
		vars->map[vars->y_pos][vars->x_pos] = 'P';
		render_map(vars, vars->map, vars->dim);
	}
}

int	key_move_hook(int keycode, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->x_pos;
	new_y = vars->y_pos;
	if (process_special_keys(keycode, vars))
		return (0);
	calculate_p(keycode, &new_x, &new_y, vars);
	if (new_x >= 0 && new_x < vars->dim.width_screen && new_y >= 0
		&& new_y < vars->dim.height_screen && vars->map[new_y][new_x] != '1')
	{
		process_map_interaction(vars, new_x, new_y);
	}
	return (0);
}
