/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 06:54:49 by yscheupl          #+#    #+#             */
/*   Updated: 2025/12/04 10:02:41 by yscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	moving_up(t_sl_data *data)
{
	moving(-1, 0, data);
}

void	moving_down(t_sl_data *data)
{
	moving(1, 0, data);
}

void	moving_left(t_sl_data *data)
{
	moving(0, -1, data);
}

void	moving_right(t_sl_data *data)
{
	moving(0, 1, data);
}

void	youve_been_movin_and_groovin(t_sl_data *data)
{
	data->count_steps++;
	ft_putstr_fd("You've swum : ", 1);
	ft_putnbr_fd(data->count_steps, 1);
	ft_putendl_fd(" Fin Steps !", 1);
}
