/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 06:54:49 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/04 11:39:37 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	moving_up(t_struct_struct *data_struct, t_sl_data *data)
{
	moving(-1, 0, data, data_struct);
}

void	moving_down(t_struct_struct *data_struct, t_sl_data *data)
{
	moving(1, 0, data, data_struct);
}

void	moving_left(t_struct_struct *data_struct, t_sl_data *data)
{
	moving(0, -1, data, data_struct);
}

void	moving_right(t_struct_struct *data_struct, t_sl_data *data)
{
	moving(0, 1, data, data_struct);
}

void	youve_been_movin_and_groovin(t_sl_data *data)
{
	data->count_steps++;
	ft_putstr_fd("You've swum : ", 1);
	ft_putnbr_fd(data->count_steps, 1);
	ft_putendl_fd(" Fin Steps !", 1);
}
