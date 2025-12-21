/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:56:49 by haya              #+#    #+#             */
/*   Updated: 2025/12/21 09:59:31 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*player_init(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->img = empty_img();
	if (!player->img)
	{
		safe_free((void **)&player);
		return (NULL);
	}
	player->collect_count = 0;
	set_player_position(player, map->map);
	return (player);
}

t_collectables	*collectable_init(t_map *map)
{
	t_collectables	*collectables;

	collectables = malloc(sizeof(t_collectables));
	if (!collectables)
		return (NULL);
	collectables->img = empty_img();
	if (!collectables->img)
	{
		safe_free((void **)&collectables);
		return (NULL);
	}
	set_collectable_count(collectables, map->map);
	return (collectables);
}

t_exit	*exit_init(t_map *map)
{
	t_exit	*exit;

	exit = malloc(sizeof(t_exit));
	if (!exit)
	{
		map->exit = NULL;
		return (NULL);
	}
	exit->status = 0;
	exit->closed = empty_img();
	if (!exit->closed)
	{
		safe_free((void **)&exit);
		return (NULL);
	}
	exit->opened = empty_img();
	if (!exit->opened)
	{
		safe_free((void **)&exit->closed);
		safe_free((void **)&exit);
		return (NULL);
	}
	set_exit_position(exit, map->map);
	return (exit);
}

void	initialize_game_object(t_map *map)
{
	map->player = player_init(map);
	map->collectables = collectable_init(map);
	map->exit = exit_init(map);
	map->wall = empty_img();
	map->floor = empty_img();
	map->player_door = empty_img();
	map->p_moves = 0;
}

t_map	*initialize_map(char **content)
{
	t_map	*map;

	if (!(*content))
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = calc_height((*content));
	map->width = calc_width((*content));
	map->map = ft_split((*content), '\n');
	if (!map->map)
	{
		safe_free((void **)&map);
		return (NULL);
	}
	initialize_game_object(map);
	if (check_mallocked(map) == 0)
	{
		free_map(map);
		return (NULL);
	}
	safe_free((void **)content);
	return (map);
}
