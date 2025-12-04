/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 07:24:37 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/04 11:04:50 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	moving(int up_down, int left_right, t_sl_data *data, t_struct_struct *struct_struct)
{
	int	*player_pos;

	player_pos = find_player_position;
	if (data->map[player_pos[0] + up_down][player_pos[1] + left_right] == '0')
	{
		data->map[player_pos[0]][player_pos[1]] = '0';
		data->map[player_pos[0] + up_down][player_pos[1] + left_right] = 'P';
		if (data->exit_pos[0] == player_pos[0] + up_down
			&& data->exit_pos[1] == player_pos[1] + left_right)
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
	
}

void	moving_further(t_sl_data *data, int *player_pos, int up_down, int left_right, t_struct_struct *struct_struct)
{
	if (data->map[player_pos[0] + up_down][player_pos[1] + left_right] == 'E'
		&& data->num_c == 0)
	{
		free(player_pos);
		ending_the_game(struct_struct)
	}
	if (data->map[player_pos[0] + up_down][player_pos[1] + left_right] == 'E'
		&& data->num_c != 0)
	{
		data->exit_pos[0] = player_pos[0] + left_right;
		data->exit_pos[1] = player_pos[1] + up_down;
		data->map[player_pos[0]][player_pos[1]] = '0';
		data->map[player_pos[0] + up_down][player_pos[1] + left_right] = 'P';
	}
	youve_been_movin_and_groovin(data);
	free(player_pos);
}

void	ending_the_game(t_struct_struct *struct_struct)
{
	youve_been_movin_and_groovin(struct_struct->data);
	ft_putendl_fd("You Win!", 1);
	closing(struct_struct);
}
