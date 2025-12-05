/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 23:27:44 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/05 18:45:20 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_sl_data *data)
{
	data->map = NULL;
	data->cpy_map = NULL;
	data->map_file = NULL;
	data->exit_pos = malloc(sizeof(int) * 2);
	data->exit_pos[0] = 0;
	data->exit_pos[1] = 0;
	data->num_p = 0;
	data->num_e = 0;
	data->num_c = 0;
	data->count_steps = 0;
}

void	error_management(int error_code)
{
	if (error_code == ERR_ARGC)
		ft_putendl_fd("Error : Invalid number of arguments", 2);
	else if (error_code == ERR_FILE)
		ft_putendl_fd("Error : The file loader failed", 2);
	else if (error_code == ERR_MAP_WALLS)
		ft_putendl_fd("Error : The map walls test failed", 2);
	else if (error_code == ERR_MAP_RECT)
		ft_putendl_fd("Error : The map squareness test failed", 2);
	else if (error_code == ERR_MAP_CHARS)
		ft_putendl_fd("Error : The map characters test failed", 2);
	else if (error_code == ERR_MAP_PATH)
		ft_putendl_fd("Error : The map path test failed", 2);
	else if (error_code == ERR_MALLOC)
		ft_putendl_fd("Error : Memory allocation failed", 2);
	else if (error_code == ERR_MAP_SIZE)
		ft_putendl_fd("Error : The map size test failed", 2);
}

int	main(int argc, char **argv)
{
	t_sl_data	data;
	int			error_code;

	init_data(&data);
	if (argc != 2)
		return (error_management(ERR_ARGC), free(data.exit_pos), ERR_ARGC);
	data.map_file = ft_strdup(argv[1]);
	if (!data.map_file)
		return (error_management(ERR_MALLOC), free(data.exit_pos),
			free(data.map_file), ERR_MALLOC);
	error_code = parsing(&data);
	if (error_code != SUCCESS)
		return (error_management(error_code), free(data.exit_pos),
			free(data.map_file), error_code);
	mlx_management(&data);
	return (free(data.exit_pos), free(data.map_file), SUCCESS);
}
