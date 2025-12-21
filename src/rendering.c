/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:24:12 by hal-lawa          #+#    #+#             */
/*   Updated: 2025/12/21 10:44:47 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	*render_door(t_map *map, int i, int j)
{
	t_img	*img;

	if (map->map[i][j] == 'P')
		img = map->player_door;
	else
	{
		if (map->exit->status == 1)
			img = map->exit->opened;
		else
			img = map->exit->closed;
	}
	return (img);
}

static t_img	*get_img(t_map *map, int i, int j)
{
	t_img	*img;

	img = map->floor;
	if (i == map->exit->y && j == map->exit->x)
		img = render_door(map, i, j);
	else if (map->map[i][j] == '1')
		img = map->wall;
	else if (map->map[i][j] == 'C')
		img = map->collectables->img;
	else if (map->map[i][j] == 'P')
		img = map->player->img;
	return (img);
}

void	render_map(t_map *map, void *mlx, void *mlx_win)
{
	int		i;
	int		j;
	t_img	*img;

	i = 0;
	img = map->floor;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			img = get_img(map, i, j);
			mlx_put_image_to_window(mlx, mlx_win, img->data, j * img->w, i
				* img->h);
			j++;
		}
		i++;
	}
}
