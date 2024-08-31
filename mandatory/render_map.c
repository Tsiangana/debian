/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:13:55 by pzau              #+#    #+#             */
/*   Updated: 2024/08/17 16:06:20 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*get_image_for_cell(t_vars *vars, char cell)
{
	if (cell == '1')
		return (vars->img_0);
	else if (cell == 'P')
		return (vars->img_p);
	else if (cell == 'C')
		return (vars->img_c);
	else if (cell == 'E')
		return (vars->img_e);
	else if (cell == '0')
		return (vars->img_wall);
	return (NULL);
}

void	render_map_line(t_vars *vars, char **map, int y, int width)
{
	void	*img;
	int		x;
	char	cell;

	x = 0;
	while (x < width)
	{
		cell = map[y][x];
		img = get_image_for_cell(vars, cell);
		if (img)
			mlx_put_image_to_window(vars->mlx, vars->win,
				img, x * PIX, y * PIX);
		x++;
	}
}

void	render_map(t_vars *vars, char **map, t_dimensoes dim)
{
	int	y;

	y = 0;
	while (y < dim.height_screen)
	{
		render_map_line(vars, map, y, dim.width_screen);
		y++;
	}
}
