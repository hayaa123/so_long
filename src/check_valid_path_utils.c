/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:15:08 by hal-lawa          #+#    #+#             */
/*   Updated: 2025/12/24 10:04:26 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		safe_free((void **)&(map[i]));
		i++;
	}
	safe_free((void **)&map);
}

char	**cpy_map(t_map *map)
{
	int		i;
	char	**cpy;

	if (!map)
		return (NULL);
	if (!map->map)
		return (NULL);
	cpy = malloc(sizeof(char *) * (map->height + 1));
	i = 0;
	if (!cpy)
		return (NULL);
	while (map->map[i])
	{
		cpy[i] = ft_strdup(map->map[i]);
		if (!cpy[i])
		{
			free_grid(cpy);
			return (NULL);
		}
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
