/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 08:24:01 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/04 10:58:38 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	what_has_been_pressed(int key, t_sl_data *data)
{
	if (key == ESC_KEY)
		closing();
	else if (key == W_KEY)
		moving_up(data);
	else if (key == S_KEY)
		moving_down(data);
	else if (key == A_KEY)
		moving_left(data);
	else if (key == D_KEY)
		moving_right(data);
	return (SUCCESS);
}
void	assets_management(t_mlx *mlx_data, int width, int height)
{
	mlx_data->assets[0] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Wall.xpm", &width, &height);
	mlx_data->assets[1] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Floor.xpm", &width, &height);
	mlx_data->assets[2] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Exit.xpm", &width, &height);
	mlx_data->assets[3] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Player.xpm", &width, &height);
	mlx_data->assets[4] = mlx_xpm_file_to_image(mlx_data->mlx,
			"assets/Collectible.xpm", &width, &height);
}

int	closing(t_struct_struct *struct_struct)
{
	mlx_destroy_image(struct_struct->mlx_data->mlx, struct_struct->mlx_data->img);
	mlx_destroy_image(struct_struct->mlx_data->mlx, struct_struct->mlx_data->assets[0]);
	mlx_destroy_image(struct_struct->mlx_data->mlx, struct_struct->mlx_data->assets[1]);
	mlx_destroy_image(struct_struct->mlx_data->mlx, struct_struct->mlx_data->assets[2]);
	mlx_destroy_image(struct_struct->mlx_data->mlx, struct_struct->mlx_data->assets[3]);
	mlx_destroy_image(struct_struct->mlx_data->mlx, struct_struct->mlx_data->assets[4]);
	mlx_destroy_window(struct_struct->mlx_data->mlx, struct_struct->mlx_data->win);
	mlx_destroy_display(struct_struct->mlx_data->mlx);
	free(struct_struct->mlx_data->mlx);
	free(struct_struct->mlx_data->assets);
	free(struct_struct->data->exit_pos);
	free_tab(struct_struct->data->map);
	exit(EXIT_SUCCESS);
}
void	ft_initialize_window(t_mlx *mlx_data, t_sl_data *data, int i, int j)
{
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[0], j * 32, i * 32);
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[1], j * 32, i * 32);
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[2], j * 32, i * 32);
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[3], j * 32, i * 32);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->win,
					mlx_data->assets[4], j * 32, i * 32);
			j++;
		}
		i++;
	}
}


void	mlx_management(t_sl_data *data)
{
	t_mlx			mlx_data;
	t_struct_struct	struct_struct;

	struct_struct.data = data;
	struct_struct.mlx_data = &mlx_data;
	mlx_data.mlx = mlx_init();
	mlx_data.assets = malloc(sizeof(void *) * 5);
	assets_management(&mlx_data, 32, 32);
	mlx_data.win = mlx_new_window(mlx_data.mlx, 32 * ft_strlen(data->map[0]), 32
			* ((what_is_the_last_line(data)) + 1), "so_long");
	mlx_data.img = mlx_new_image(mlx_data.mlx, 32 * ft_strlen(data->map[0]), 32
			* ((what_is_the_last_line(data) + 1)));
	window_initialization(&mlx_data, data, 0, 0);
	mlx_hook(mlx_data.win, 17, 0, closing, &struct_struct);
	if (mlx_key_hook(mlx_data.win, what_has_been_pressed, &struct_struct) == 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	mlx_loop(mlx_data.mlx);
}
