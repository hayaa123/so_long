/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:11:41 by hal-lawa          #+#    #+#             */
/*   Updated: 2025/12/21 10:45:16 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_game_elements(t_vars *vars)
{
	if (!vars->map)
		return (0);
	if (!vars->map->floor->data || !vars->map->wall->data
		|| !vars->map->player->img->data || !vars->map->collectables->img->data
		|| !vars->map->player_door->data || !vars->map->exit->closed->data
		|| !vars->map->exit->opened->data)
		return (0);
	if (!vars->win)
		return (0);
	return (1);
}
