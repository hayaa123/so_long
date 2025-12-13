/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haya <haya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:34:14 by haya              #+#    #+#             */
/*   Updated: 2025/12/13 17:54:08 by haya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int *get_start_coord(char **grid)
{
    int i;
    int j;
    int *start_coord;
    
    i = 0;
    start_coord = malloc(sizeof(int) * 2);
    while(grid[i])
    {
        j = 0;
        while(grid[i][j])
        {
            if (grid[i][j] == 'P')
            {
                start_coord[0] = i;
                start_coord[1] = j;
                break;
            }
            j++;
        }
        i++;
    }
    return start_coord;
}

static void dfs(char **grid, int row, int col, char visited)
{
    if (grid[row][col] == '1' || grid[row][col] == visited)
        return;
    grid[row][col] = visited;
    dfs(grid,row + 1, col, visited);
    dfs(grid,row, col + 1, visited);
    dfs(grid,row - 1, col, visited);
    dfs(grid,row , col -1, visited);
}

static int check_existed(char **grid)
{
    int i;
    int j;
    
    i = 0;
    while(grid[i])
    {
        j = 0;
        while(grid[i][j])
        {
            if (grid[i][j] == 'P' || grid[i][j] == 'E' || grid[i][j] == 'C')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void helper_print(char **grid)
{
    int i;
    
    i = 0;
    while(grid[i])
    {
        ft_printf("%s\n", grid[i]);
        i++;
    }
}

int validate_path(t_map map)
{
    char **grid;
    char visited;
    int *start_coord;
    
    grid = map.map;
    visited = 'V';
    start_coord = get_start_coord(grid);
    dfs(grid, start_coord[0],start_coord[1], visited);
    if (check_existed(grid) == 0)
    {
        free(start_coord);
        return (0);
    }
    free(start_coord);
    return (1);
}
