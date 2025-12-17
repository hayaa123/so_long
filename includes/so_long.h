/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:26:07 by haya              #+#    #+#             */
/*   Updated: 2025/12/17 16:31:05 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "unistd.h"
# include "stdio.h"
# include <errno.h>
# include <string.h>
# include "fcntl.h"
# include <mlx.h>

# define IMAGE_WIDTH 32
# define IMAGE_HEIGHT 32
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_img{
    void *data;
    int w;
    int h;
} t_img;

typedef struct s_player {
    t_img *img;
    int x;
    int y;
    int collect_count;
} t_player;

typedef struct s_collectables
{
    t_img *img;
    int count;   
} t_collectables;

typedef struct s_exit
{
    int status;
    int x;
    int y;
    t_img *closed;
    t_img *opened;
} t_exit;

typedef struct s_map {
    int width;
    int height;
    char **map;
    t_player *player;
    t_img *floor;
    t_img *wall;
    t_img *player_door;
    t_exit *exit;
    t_collectables *collectables;
} t_map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    t_map    *map;
}				t_vars;


char *read_as_line(char *filename);
int validate_map(t_map *map);
t_map *initialize_map(char *content);
int validate_path(t_map *map);
void helper_print(char **grid); // @TODO: Remove it after finishing the project.
void free_map(t_map *map);
void start_game(t_map *map);
void move_up(t_map *map);
void move_down(t_map *map);
void move_right(t_map *map);
void move_left(t_map *map);

#endif