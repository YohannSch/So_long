/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 07:24:37 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/04 15:53:23 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	moving(int up_down, int left_right, t_sl_data *data,
		t_struct_struct *struct_struct)
{
	int	*player_pos;

	player_pos = find_player_position(data);
	if (!player_pos)
		return ;
	if (data->map[player_pos[0] + up_down][player_pos[1] + left_right] == '0')
	{
		data->map[player_pos[0]][player_pos[1]] = '0';
		data->map[player_pos[0] + up_down][player_pos[1] + left_right] = 'P';
		if (data->exit_pos[0] == player_pos[0]
			&& data->exit_pos[1] == player_pos[1])
			data->map[player_pos[0]][player_pos[1]] = 'E';
	}
	if (data->map[player_pos[0] + up_down][player_pos[1] + left_right] == 'C')
	{
		data->map[player_pos[0]][player_pos[1]] = '0';
		data->map[player_pos[0] + up_down][player_pos[1] + left_right] = 'P';
		data->num_c--;
		if (data->exit_pos[0] == player_pos[0]
			&& data->exit_pos[1] == player_pos[1])
			data->map[player_pos[0]][player_pos[1]] = 'E';
	}
	moving_further(player_pos, up_down, left_right, struct_struct);
}

void	moving_further(int *player_pos, int up_down, int left_right,
			t_struct_struct *struct_struct)
{
	if (struct_struct->data->map[player_pos[0] + up_down][player_pos[1]
		+ left_right] == 'E' && struct_struct->data->num_c == 0)
	{
		window_initialization(struct_struct->mlx_data, struct_struct->data, 32,
			32);
		free(player_pos);
		ending_the_game(struct_struct);
	}
	if (struct_struct->data->map[player_pos[0] + up_down][player_pos[1]
		+ left_right] == 'E' && struct_struct->data->num_c != 0)
	{
		// struct_struct->data->exit_pos[0] = player_pos[0] + left_right;
		// struct_struct->data->exit_pos[1] = player_pos[1] + up_down;
		struct_struct->data->map[player_pos[0]][player_pos[1]] = '0';
		struct_struct->data->map[player_pos[0] + up_down][player_pos[1]
			+ left_right] = 'P';
	}
	youve_been_movin_and_groovin(struct_struct->data);
	window_initialization(struct_struct->mlx_data, struct_struct->data, 32, 32);
	free(player_pos);
}

void	ending_the_game(t_struct_struct *struct_struct)
{
	youve_been_movin_and_groovin(struct_struct->data);
	ft_putendl_fd("You Win!", 1);
	closing(struct_struct);
}
