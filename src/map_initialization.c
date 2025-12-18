/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:56:49 by haya              #+#    #+#             */
/*   Updated: 2025/12/18 14:20:12 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*empty_img(void)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->data = NULL;
	img->h = 0;
	img->w = 0;
	return (img);
}

void	player_init(t_map *map)
{
	int			i;
	int			j;
	t_player	*player;

	i = 0;
	j = 0;
	player = malloc(sizeof(t_player));
	if(!player)
	{
		map->player = NULL;
		return ;		
	}
	player->img = empty_img();
	player->collect_count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
			}
			j++;
		}
		i++;
	}
	map->player = player;
}

void	collectable_init(t_map *map)
{
	int				i;
	int				j;
	t_collectables	*collectables;

	i = 0;
	j = 0;
	collectables = malloc(sizeof(t_collectables));
	collectables->img = empty_img();
	collectables->count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
			{
				collectables->count++;
			}
			j++;
		}
		i++;
	}
	map->collectables = collectables;
}

void	exit_init(t_map *map)
{
	int		i;
	int		j;
	t_exit	*exit;

	i = 0;
	j = 0;
	exit = malloc(sizeof(t_exit));
	if (!exit)
	{
		map->exit = NULL;
		return;	
	}
	exit->status = 0;
	exit->closed = empty_img();
	exit->opened = empty_img();
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'E')
			{
				exit->x = j;
				exit->y = i;
			}
			j++;
		}
		i++;
	}
	map->exit = exit;
}

int check_mallocked(t_map *map)
{
	if(!map->map)
		return (0);
	if(!map->exit || !map->player)
		return (0);
	if(!map->exit->closed || !map->exit->opened)
		return (0);
	if(!map->collectables)
		return (0);
	if(!map->floor || !map->wall)
		return (0);
	if(!map->player_door)
		return (0);
	return (1);
}

t_map	*initialize_map(char *content)
{
	t_map	*map;

	if (!content)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = calc_height(content);
	map->width = calc_width(content);
	map->map = ft_split(content, '\n');
	player_init(map);
	collectable_init(map);
	exit_init(map);
	map->wall = empty_img();
	map->floor = empty_img();
	map->player_door = empty_img();
	map->p_moves = 0;
	free(content);
	content = NULL;
	if(check_mallocked(map) == 0)
	{
		free_map(map);
		map = NULL;
		return (NULL);
	}
	return (map);
}
