// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/12/13 14:32:38 by haya              #+#    #+#             */
// /*   Updated: 2025/12/15 10:20:02 by hal-lawa         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "so_long.h"

void free_t_img_instances(t_map *map)
{
    if (map->player)
    {
        if(map->player->img)
            free(map->player->img);
        free(map->player);
    }
    if (map->collectables)
    {
        if(map->collectables->img)
            free(map->collectables->img);
        free(map->collectables);
    }
    if (map->exit)
    {
        if(map->exit->closed)
            free(map->exit->closed);
        if(map->exit->opened)
            free(map->exit->opened);
        free(map->exit);
    }
    if(map->floor)
        free(map->floor);
    if(map->wall)
        free(map->wall);
    if(map->player_door)
        free(map->player_door);
}

void free_map(t_map *map)
{
    int i;

    i = 0;
    if (!map)
        return ;
    free_t_img_instances(map);
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
    {
        if (content)
            free(content);
        return return_error("Somthing went wrong\n", 2, map);
    }
    if(validate_map(map) == 0)
        return return_error("Invalid map\n", 4, map);
    if(validate_path(map) == 0)
		return return_error("no valid path in the map\n", 4, map);
	start_game(map);
	free_map(map);
    return (0);
}
// #include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// int	main(void)
// {
// 	void	*mlx;
//     void	*mlx_win;
//     t_data    img;

//     my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

//     mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

//     mlx_loop(mlx);
// }
// #include <mlx.h>

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	void	*img;
// 	char	*relative_path = "./gray_brick.xpm";
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "game");
// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);

// 	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
// 	mlx_put_image_to_window(mlx, mlx_win, img, img_width, 0);

// 	mlx_loop(mlx);
// }