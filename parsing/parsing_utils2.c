/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 06:41:31 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/04 06:42:04 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	*find_player_position(t_sl_data *data)
{
	int	i;
	int	j;
	int	*res;

	i = 0;
	res = malloc(sizeof(int) * 2);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				res[0] = i;
				res[1] = j;
				return (res);
			}
			j++;
		}
		i++;
	}
}

void	copy_map(t_sl_data *data)
{
	int				i;
	unsigned long	j;

	i = 0;
	data->cpy_map = malloc(sizeof(char *) * (what_is_the_last_line(data) + 2));
	while (data->map[i])
	{
		j = 0;
		data->cpy_map[i] = malloc(sizeof(char) * (ft_strlen(data->map[i]) + 1));
		while (data->map[i][j])
		{
			data->cpy_map[i][j] = data->map[i][j];
			j++;
		}
		data->cpy_map[i][j] = '\0';
		i++;
	}
	data->cpy_map[i] = NULL;
}

int	what_is_the_last_line(t_sl_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	i--;
	return (i);
}

int	check_path(t_sl_data *data)
{
	int	*player_pos;
	int	tmp;

	tmp = data->num_c;
	player_pos = find_player_position(data);
	copy_map(data);
	if (flood_fill(data, player_pos[0], player_pos[1]) != SUCCESS)
		return (free(player_pos), free_tab(data->cpy_map), ERR_MAP_PATH);
	if (data->num_c != 0)
		return (free(player_pos), free_tab(data->cpy_map), ERR_MAP_PATH);
	data->num_c = tmp;
	return (free(player_pos), free_tab(data->cpy_map), SUCCESS);
}

int	flood_fill(t_sl_data *data, int x, int y)
{
	if (x < 0 || x >= what_is_the_last_line(data) || y < 0
		|| y >= ft_strlen(data->cpy_map[0]))
		return (ERR_MAP_PATH);
	if (data->cpy_map[x][y] == '1' || data->cpy_map[x][y] == 's')
		return (ERR_MAP_PATH);
	if (data->cpy_map[x][y] == 'C')
	{
		data->cpy_map[x][y] = '0';
		data->num_c--;
	}
	if (data->cpy_map[x][y] == 'E')
		data->num_e--;
	if ((data->cpy_map[x][y] == 'E' || data->num_e == 0) && data->num_c == 0)
		return (SUCCESS);
	data->cpy_map[x][y] = 'V';
	if (flood_fill(data, x, y + 1) == SUCCESS)
		return (SUCCESS);
	if (flood_fill(data, x, y - 1) == SUCCESS)
		return (SUCCESS);
	if (flood_fill(data, x + 1, y) == SUCCESS)
		return (SUCCESS);
	if (flood_fill(data, x - 1, y) == SUCCESS)
		return (SUCCESS);
	return (ERR_MAP_PATH);
}
