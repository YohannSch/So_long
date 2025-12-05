/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 06:40:17 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/05 15:34:33 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	load_map(t_sl_data *data)
{
	int		file_descriptor;
	char	*line;
	char	*text;
	char	*tmp;

	file_descriptor = open(data->map_file, O_RDONLY);
	if (file_descriptor < 0)
		return (ERR_FILE);
	line = get_next_line(file_descriptor);
	if (!line)
		return (ERR_FILE);
	text = ft_strdup("");
	while (line)
	{
		tmp = text;
		text = ft_strjoin(text, line);
		free(tmp);
		free(line);
		line = get_next_line(file_descriptor);
	}
	close(file_descriptor);
	data->map = ft_split(text, '\n');
	if (!data->map)
		return (free(line),free(text), ERR_FILE);
	return (free(line), free(text), SUCCESS);
}

int	check_map_squareness(t_sl_data *data)
{
	int	i;
	int	row_length;

	i = 0;
	row_length = ft_strlen(data->map[i]);
	if (row_length > 60)
		return (ERR_MAP_SIZE);
	while (data->map[i])
	{
		if ((int)ft_strlen(data->map[i]) != row_length)
			return (ERR_MAP_RECT);
		i++;
	}
	if (i > 32)
		return (ERR_MAP_SIZE);
	return (SUCCESS);
}

int	check_map_characters(t_sl_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1'
				&& data->map[i][j] != 'C' && data->map[i][j] != 'E'
				&& data->map[i][j] != 'P')
			{
				return (ERR_MAP_CHARS);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_characters(t_sl_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				data->num_p++;
			else if (data->map[i][j] == 'E')
			{
				data->num_e++;
				data->exit_pos[0] = i;
				data->exit_pos[1] = j;
			}
			else if (data->map[i][j] == 'C')
				data->num_c++;
			j++;
		}
		i++;
	}
	if (data->num_p != 1 || data->num_e != 1 || data->num_c < 1)
		return (ERR_MAP_CHARS);
	return (SUCCESS);
}

int	check_map_walls(t_sl_data *data)
{
	int	i;
	int	last_row;

	last_row = 0;
	while (data->map[last_row])
		last_row++;
	last_row--;
	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1' || data->map[last_row][i] != '1')
			return (ERR_MAP_WALLS);
		i++;
	}
	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][ft_strlen(data->map[i])
			- 1] != '1')
			return (ERR_MAP_WALLS);
		i++;
	}
	return (SUCCESS);
}
