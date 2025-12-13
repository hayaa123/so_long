/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haya <haya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:32:38 by haya              #+#    #+#             */
/*   Updated: 2025/12/13 19:08:35 by haya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_map *map)
{
    int i;

    i = 0;
    if (!map)
        return;
    if (map->map)
    {
        while ((map->map)[i])
        {
            free((map->map)[i]);
            i++;
        }
    }
    free(map->map);
    free(map);
}

static int return_error(char *msg, int code, t_map *map)
{
    if (map)
        free_map(map);
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(msg, 2);
    return (code);
}

int main(int argc, char **argv)
{
    char *content;
    t_map *map;

    if(argc != 2)
        return return_error("The programm takes 1 parameter\n", 1, NULL);
    content = read_as_line(argv[1]);
    if(!content)
        return return_error("Somthing went wrong\n", 2, NULL);
    map = initialize_map(content);
    if(!map || !(map->map))
        return return_error("Somthing went wrong\n", 2, map);
    if(validate_map(map) == 0)
        return return_error("Invalid map\n", 3,map);
    if(validate_path(*map) == 0)
        return return_error("no valid path in the map\n", 4, map);
    //start game
    free_map(map);
    return (0);
}
