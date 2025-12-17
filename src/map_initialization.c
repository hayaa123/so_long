/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:56:49 by haya              #+#    #+#             */
/*   Updated: 2025/12/17 16:58:42 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img *empty_img()
{
	t_img *img;
	
	img = malloc(sizeof(t_img));
	if (!img)
        return NULL;
	img->data = NULL;
	img->h = 0;
	img->w = 0;
	return (img);
}
static int calc_height(char *content)
{
    int i;
    int line;
    
    i = 0;
    line = 0;
    if(!content)
        return (0);
    while(content[i])
    {
        if(content[i + 1] == '\n' || content[i + 1] == '\0')
        {
            line++;
            if (content[i + 1] == '\n' )
                i++;
            i++;
            continue;
        }   
        i++;
    }
    return (line);
}

static int calc_width(char *content)
{
    int i;
        
    i = 0;
    if(!content)
        return (0);
    while(content[i])
    {
        if(content[i] == '\n' || content[i] == '\0')
            break;
        i++;
    }
    return (i);
}

void player_init(t_map *map)
{
    int i;
    int j;
    t_player *player;
    
    i = 0;
    j = 0;
    player = malloc(sizeof(t_player));
    player->img = empty_img();
    player->collect_count = 0;
    while(map->map[i])
    {
        j = 0;
		while(map->map[i][j])
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

void collectable_init(t_map *map)
{
    int i;
    int j;
    t_collectables *collectables;
    
    i = 0;
    j = 0;
    collectables = malloc(sizeof(t_collectables));
    collectables->img = empty_img();
    collectables->count =0;
	while(map->map[i])
    {
        j = 0;
        // while(j < map->width/)
		while(map->map[i][j])
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

void exit_init(t_map *map)
{
    int i;
    int j;
    t_exit *exit;
    
    i = 0;
    j = 0;
    exit = malloc(sizeof(t_exit));
    exit-> status = 0;
    exit->closed = empty_img();
    exit->opened = empty_img();
    while(map->map[i])
    {
        j = 0;
		while(map->map[i][j])
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

t_map *initialize_map(char *content)
{
    t_map *map;
    
	
    map = malloc(sizeof(t_map));
    if (!content)
        return (NULL);
    if (!map)
        return (NULL);
    map->height = calc_height(content);
    map->width = calc_width(content);
    map->map  = ft_split(content, '\n');
	player_init(map);
    collectable_init(map);
    exit_init(map);
    map->wall = empty_img();
    map->floor = empty_img();
    map->player_door = empty_img();
    free(content);
    content = NULL;
    return (map);
}
