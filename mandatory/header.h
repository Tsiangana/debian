/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzau <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:52:13 by pzau              #+#    #+#             */
/*   Updated: 2024/08/23 18:05:40 by pzau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../minilibx-linux/mlx.h"
# include "my_printf/ft_printf.h"

# define PIX 50

typedef struct s_game_state
{
	int	**visited;
	int	collectables_left;
	int	exit_reachable;
}	t_game_state;

typedef struct s_dimensoes
{
	int	height_screen;
	int	width_screen;
}	t_dimensoes;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game_info
{
	t_game_state	state;
	t_dimensoes		dimensoes;
}	t_game_info;

typedef struct s_vars
{
	t_game_info	game_info;
	t_dimensoes	dim;
	t_point		start_point;
	void		*mlx;
	void		*win;
	void		*img_0;
	void		*img_p;
	void		*img_c;
	void		*img_e;
	void		*img_wall;
	char		**map;
	char		**map_copy;
	int			img_width_img;
	int			img_height_img;
	int			coletaveis;
	int			x_pos;
	int			y_pos;
	int			steps;
}	t_vars;

void		disp_file(int fd, t_dimensoes *dim);
void		dimention(char *fdf, t_dimensoes *dim);
void		*get_image_for_cell(t_vars *vars, char cell);
void		free_split(char **matrix);
void		flood_fill(int x, int y, t_vars *vars);
void		flood(int x, int y, t_vars *vars);
void		finding_start_point(char **matrix, t_vars *vars, char c);
void		sending_to_flood_fill(t_vars *vars);
void		finish_that_stupid_verifications(t_vars *vars);
void		initialize_map_copy(t_vars *vars);
void		rest_all(t_vars *vars);
void		fill_matrix(char **matrix, char *s, int words);
void		render_map_line(t_vars *vars, char **map, int y, int width);
void		load_imagens(t_vars *vars);
void		fd_last(void);
void		func_close(t_vars *vars);
void		verify_playability(t_game_info *game_info, t_vars *vars);
void		free_images(t_vars *vars);
void		init_visited_and_collectables(t_game_info *game_info, char **map);
void		free_visited(t_game_info *game_info);
void		init_player_position(t_vars *vars);
void		find_player_position_init(t_vars *vars);
void		free_visited(t_game_info *game_info);
void		render_map(t_vars *vars, char **map, t_dimensoes dim);
void		process_map_interaction(t_vars *vars, int new_x, int new_y);
void		calculate_p(int keycode, int *new_x, int *new_y, t_vars *vars);
void		validate_player(char **map, t_dimensoes *dim, t_vars *vars);
void		validate_colector(char **map, t_dimensoes *dim, t_vars *vars);
void		init_visited_and_collectables(t_game_info *game_info, char **map);
void		validate_exit(char **map, t_dimensoes *dim, t_vars *vars);
void		validate_rectangle(char **map, t_dimensoes *dim, t_vars *vars);
char		**ft_split(char *s);
char		*append_to_content(char *content, char *buffer);
char		*ft_strdup(char *str);
char		*ft_strcat(char *dest, const char *src);
char		**print_map(const char *filename);
char		*allocate_word(const char *start, int length);
char		**allocate_matrix(int words);
char		**copy_matrix(char **matrix, int rows, int cols);
int			is_map_closed(char **map, int height, int width);
int			strchr_on_matrix(char **matrix, char c);
int			find_player_position(char **map, t_game_info *game_info);
int			key_move_hook(int keycode, t_vars *vars);
int			all_things(char **map, t_dimensoes *dim, t_vars *vars);
int			process_special_keys(int keycode, t_vars *vars);
int			delimiter(char c);
int			ft_strlen(const char *str);
int			close_x(void *param);
int			count_words(char *s);

#endif
