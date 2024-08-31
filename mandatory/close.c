/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:50:38 by pzau              #+#    #+#             */
/*   Updated: 2024/08/17 18:03:00 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	close_x(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	free_images(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free_split(vars->map);
	free_split(vars->map_copy);
	free(vars->mlx);
	exit(0);
}
