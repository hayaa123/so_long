/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:28:34 by hal-lawa          #+#    #+#             */
/*   Updated: 2025/12/18 12:10:32 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_win(t_vars *vars)
{
	t_map	*map;

	map = vars->map;
	if (map->player->x == map->exit->x && map->player->y == map->exit->y)
	{
		if (map->exit->status == 1)
		{
			printf("Congratiolations YAAAAAAAAY!\n");
			exit_game(vars);
		}
	}
	if (vars->map->player->collect_count == vars->map->collectables->count)
		vars->map->exit->status = 1;
}

static void	move_and_render(t_vars *vars, void (*f)(t_map *))
{
	f(vars->map);
	check_win(vars);
	render_map(vars->map, vars->mlx, vars->win);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == W)
		move_and_render(vars, move_up);
	else if (keycode == A)
		move_and_render(vars, move_left);
	else if (keycode == S)
		move_and_render(vars, move_down);
	else if (keycode == D)
		move_and_render(vars, move_right);
	else if (keycode == ESC)
		exit_game(vars);
	return (0);
}

void	assign_images(void *mlx, t_map *map)
{
	map->floor->data = mlx_xpm_file_to_image(mlx, "textures/grass_32.xpm",
			&map->floor->w, &map->floor->h);
	map->wall->data = mlx_xpm_file_to_image(mlx, "textures/wall_32.xpm",
			&map->wall->w, &map->wall->h);
	map->player_door->data = mlx_xpm_file_to_image(mlx,
			"textures/player_door.xpm", &map->player_door->w,
			&map->player_door->h);
	map->player->img->data = mlx_xpm_file_to_image(mlx,
			"textures/player_32.xpm", &map->player->img->w,
			&map->player->img->h);
	map->collectables->img->data = mlx_xpm_file_to_image(mlx,
			"textures/crystal_32.xpm", &map->collectables->img->w,
			&map->collectables->img->h);
	map->exit->opened->data = mlx_xpm_file_to_image(mlx,
			"textures/opened_door_32.xpm", &map->exit->opened->w,
			&map->exit->opened->h);
	map->exit->closed->data = mlx_xpm_file_to_image(mlx,
			"textures/closed_door_32.xpm", &map->exit->closed->w,
			&map->exit->closed->h);
}

void	start_game(t_map *map)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	assign_images(vars.mlx, map);
	vars.map = map;
	vars.win = mlx_new_window(vars.mlx, IMAGE_WIDTH * map->width, IMAGE_HEIGHT
			* map->height, "So Long - 42");
	render_map(map, vars.mlx, vars.win);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_game, &vars);
	mlx_loop(vars.mlx);
}
