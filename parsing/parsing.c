/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 23:16:54 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/04 10:15:38 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	parsing(t_sl_data *data)
{
	int	length;

	length = ft_strlen(data->map_file);
	if (length < 4 || ft_strncmp(&data->map_file[length - 4], ".ber",
			4) != SUCCESS)
		return (free(data->map_file), ERR_FILE);
	if ((data->map_file[length - 5] == '/' || data->map_file[length - 5] == '.')
		&& ft_isascii(data->map_file[length - 5]) == SUCCESS)
		return (free(data->map_file), ERR_FILE);
	if (load_map(data) != SUCCESS)
		return (free(data->map_file), free_tab(data->map), ERR_FILE);
	if (check_map_squareness(data) != SUCCESS)
		return (free(data->map_file), free_tab(data->map), check_map_squareness(data));
	if (check_map_characters(data) != SUCCESS)
		return (free(data->map_file), free_tab(data->map), ERR_MAP_CHARS);
	if (check_characters(data) != SUCCESS)
		return (free(data->map_file), free_tab(data->map), ERR_MAP_CHARS);
	if (check_map_walls(data) != SUCCESS)
		return (free(data->map_file), free_tab(data->map), ERR_MAP_WALLS);
	if (check_path(data) != SUCCESS)
		return (free(data->map_file), free_tab(data->map), ERR_MAP_PATH);
	return (SUCCESS);
}
