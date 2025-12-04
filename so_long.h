/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:51:00 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/04 11:04:31 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307

typedef struct s_sl_data
{
	char		**map;
	char		**cpy_map;
	char		*map_file;
	int			*exit_pos;
	int			num_p;
	int			num_e;
	int			num_c;
	int			count_steps;
}				t_sl_data;

typedef struct s_mlx
{
	void		**assets;
	void		*img;
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct s_struct_struct
{
	t_sl_data	*data;
	t_mlx		*mlx_data;
}				t_struct_struct;

typedef enum e_sl_errors
{
	SUCCESS,
	ERR_ARGC,
	ERR_FILE,
	ERR_MAP_WALLS,
	ERR_MAP_RECT,
	ERR_MAP_CHARS,
	ERR_MAP_PATH,
	ERR_MALLOC,
	ERR_MAP_SIZE,
}				t_sl_errors;

void			error_management(int error_code);
int				parsing(t_sl_data *data);
void			init_data(t_sl_data *data);
void			free_tab(char **tab);
int				flood_fill(t_sl_data *data, int x, int y);
int				check_path(t_sl_data *data);
int				what_is_the_last_line(t_sl_data *data);
void			copy_map(t_sl_data *data);
int				*find_player_position(t_sl_data *data);
int				check_map_walls(t_sl_data *data);
int				check_characters(t_sl_data *data);
int				check_map_characters(t_sl_data *data);
int				check_map_squareness(t_sl_data *data);
int				load_map(t_sl_data *data);
void			moving_up(t_sl_data *data);
void			moving_down(t_sl_data *data);
void			moving_left(t_sl_data *data);
void			moving_right(t_sl_data *data);
void			youve_been_movin_and_groovin(t_sl_data *data);
void			moving(int up_down, int left_right, t_sl_data *data);
void			moving_further(t_sl_data *data, int *player_pos, int up_down,
					int left_right);
int				what_has_been_pressed(int key, t_sl_data data);
void			ending_the_game(t_struct_struct *struct_struct)

#endif