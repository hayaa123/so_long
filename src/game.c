/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:28:34 by hal-lawa          #+#    #+#             */
/*   Updated: 2025/12/17 17:11:56 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void destroy_images(void *mlx,t_map *map)
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
    if (map->exit->opened->data)
        mlx_destroy_image(mlx, map->exit->opened->data);
    map->exit->closed->data = NULL;
    if (map->player_door->data)
        mlx_destroy_image(mlx, map->player_door->data);
    map->player_door->data = NULL;
}
void exit_game(t_vars *vars)
{
    destroy_images(vars->mlx, vars->map);
    mlx_destroy_window(vars->mlx, vars->win);
    free_map(vars->map);
    mlx_destroy_display(vars->mlx);
    exit(0);
}

static void render_map(t_map *map, void *mlx, void *mlx_win)
{
    int i;
    int j;
    t_img *img;

    i =0;
    img = map->floor;
    while (map->map[i])
    {
        j =0;
        while (map->map[i][j])
        {
            img = map->floor;
            if(i == map->exit->y && j == map->exit->x) //door logic
            {
                if(map->map[i][j] == 'P') // if player is ontop of the door
                    img = map->player_door;
                else // when player is not stand on the door
                {
                    if(map->exit->status == 1)
                        img = map->exit->opened;
                    else
                        img = map->exit->closed;
                }
            }
            else if (map->map[i][j] == '1')
                img = map->wall;
            else if (map->map[i][j] == 'C')
                img = map->collectables->img;
            else if(map->map[i][j] == 'P')
                img = map->player->img;
            mlx_put_image_to_window(mlx,mlx_win, img->data,j * img->w, i * img->h);
            j++;
        }
        i++;
    }
}

void check_win(t_vars *vars)
{
    t_map *map;

    map = vars->map;
    if(map->player->x == map->exit->x && map->player->y == map->exit->y)
    {
        if (map->exit->status == 1)
            exit_game(vars);
    }
    if(vars->map->player->collect_count == vars->map->collectables->count)
        vars->map->exit->status = 1;
}

int	key_hook(int keycode, t_vars *vars)
{
    if (keycode == W)
    {
        move_up(vars->map);
        check_win(vars);
        render_map(vars->map, vars->mlx, vars->win);
    }
    else if(keycode == A)
    {
        move_left(vars->map);
        check_win(vars);
        render_map(vars->map, vars->mlx, vars->win);
    }
     else if(keycode == S)
    {
        move_down(vars->map);
        check_win(vars);
        render_map(vars->map, vars->mlx, vars->win);
    }
    else if(keycode == D)
    {
        move_right(vars->map);
        check_win(vars);
        render_map(vars->map, vars->mlx, vars->win);
    }
    else if(keycode == ESC)
        exit_game(vars);
    return (0);
}

void assign_images(void *mlx, t_map *map)
{
    map->floor->data = mlx_xpm_file_to_image(mlx, "./grass_32.xpm", &map->floor->w,  &map->floor->h);
    map->wall->data = mlx_xpm_file_to_image(mlx, "./wall_32.xpm", &map->wall->w,  &map->wall->h);
    map->player_door->data = mlx_xpm_file_to_image(mlx, "./player_door.xpm", &map->player_door->w,  &map->player_door->h);
    map->player->img->data = mlx_xpm_file_to_image(mlx, "./player_32.xpm", &map->player->img->w,  &map->player->img->h);
    map->collectables->img->data = mlx_xpm_file_to_image(mlx, "./crystal_32.xpm", &map->collectables->img->w,  &map->collectables->img->h);
    map->exit->opened->data = mlx_xpm_file_to_image(mlx, "./opened_door_32.xpm", &map->exit->opened->w,  &map->exit->opened->h);
    map->exit->closed->data = mlx_xpm_file_to_image(mlx, "./closed_door_32.xpm", &map->exit->closed->w,  &map->exit->closed->h);
}


void start_game(t_map *map)
{
    t_vars vars;
    // @TODO: first I should get the width and height for the image then calculate the screen size
    // then I should print all the bricks on the screen correctly.
    // add image paths to the map constuctor
    // adjust the logic to draw all the elements
    // add position to the player 
    // change position for the player
    // render after each event
    // collision detection with the walls 
    // test movement
    // collect items
    // open exit 
    // colectables
    vars.mlx = mlx_init();
    assign_images(vars.mlx, map);
    vars.map = map;
    vars.win = mlx_new_window(vars.mlx, IMAGE_WIDTH * map->width, IMAGE_HEIGHT * map-> height, "So Long - 42");
    render_map(map, vars.mlx, vars.win);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
}