/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:12:50 by hal-lawa          #+#    #+#             */
/*   Updated: 2025/12/18 14:09:17 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_t_img_instances(t_map *map)
{
	if (map->player)
	{
		if (map->player->img)
			free(map->player->img);
		free(map->player);
	}
	if (map->collectables)
	{
		if (map->collectables->img)
			free(map->collectables->img);
		free(map->collectables);
	}
	if (map->exit)
	{
		if (map->exit->closed)
			free(map->exit->closed);
		if (map->exit->opened)
			free(map->exit->opened);
		free(map->exit);
	}
}

void	free_map(t_map *map)
{
	int	i;

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
		free(map->map);
	}
	if (map->floor)
		free(map->floor);
	if (map->wall)
		free(map->wall);
	if (map->player_door)
		free(map->player_door);
	free(map);
}

static int	return_error(char *msg, int code, t_map *map)
{
	if (map)
		free_map(map);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	return (code);
}

int	validate_extention(char *filename)
{
	int		i;
	int		j;
	char	*extention;

	extention = ".ber";
	i = 0;
	j = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
		{
			while (filename[i] && extention[j])
			{
				if (extention[j] != filename[i])
					return (0);
				i++;
				j++;
			}
			if (filename[i] || extention[j])
				return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*content;
	t_map	*map;

	if (argc != 2)
		return (return_error("The programm takes 1 parameter\n", 1, NULL));
	if (validate_extention(argv[1]) == 0)
		return (return_error("not a valid file extention, should be \'.ber\'\n",
				1, NULL));
	content = read_as_line(argv[1]);
	if (!content)
		return (return_error("Somthing went wrong\n", 2, NULL));
	map = initialize_map(content);
	if (!map)
		return (return_error("Somthing went wrong\n", 2, NULL));
	if (validate_map(map) == 0)
		return (return_error("Invalid map\n", 4, map));
	if (validate_path(map) == 0)
		return (return_error("no valid path in the map\n", 4, map));
	start_game(map);
	free_map(map);
	return (0);
}
