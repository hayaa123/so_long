/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haya <haya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:56:49 by haya              #+#    #+#             */
/*   Updated: 2025/12/13 19:06:10 by haya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
    free(content);
    content = NULL;
    return (map);
}