/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:51:46 by hal-lawa          #+#    #+#             */
/*   Updated: 2025/12/24 09:59:32 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(void *mlx, t_map *map)
{
	if (map->floor->data)
		mlx_destroy_image(mlx, map->floor->data);
	map->floor->data = NULL;
	if (map->wall->data)
		mlx_destroy_image(mlx, map->wall->data);
	map->wall->data = NULL;
	if (map->player->img->data)
		mlx_destroy_image(mlx, map->player->img->data);
	map->player->img->data = NULL;
	if (map->collectables->img->data)
		mlx_destroy_image(mlx, map->collectables->img->data);
	map->collectables->img->data = NULL;
	if (map->exit->closed->data)
		mlx_destroy_image(mlx, map->exit->closed->data);
	map->exit->closed->data = NULL;
	if (map->exit->opened->data)
		mlx_destroy_image(mlx, map->exit->opened->data);
	map->exit->opened->data = NULL;
	if (map->player_door->data)
		mlx_destroy_image(mlx, map->player_door->data);
	map->player_door->data = NULL;
}

int	exit_game(t_vars *vars)
{
	destroy_images(vars->mlx, vars->map);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	free_map(vars->map);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	vars->mlx = NULL;
	exit(0);
	return (0);
}
