/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:14:02 by hal-lawa          #+#    #+#             */
/*   Updated: 2025/12/18 12:14:08 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_char(char **grid, int *count, int i, int j)
{
	if (grid[i][j] == 'P')
		count[0]++;
	else if (grid[i][j] == 'E')
		count[1]++;
	else if (grid[i][j] == 'C')
		count[2]++;
	else if (grid[i][j] != '\n' && grid[i][j] != '1' && grid[i][j] != '0')
		return (0);
	return (1);
}

static int	valid_char(char **grid)
{
	int	i;
	int	j;
	int	count[3];

	i = 0;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (!is_valid_char(grid, count, i, j))
				return (0);
			j++;
		}
		i++;
	}
	if (count[0] != 1 || count[1] != 1 || count[2] < 1)
		return (0);
	return (1);
}

static int	check_rect(char **grid)
{
	int	i;
	int	p_count;
	int	c_count;

	i = 0;
	p_count = 0;
	c_count = 0;
	while (grid[i])
	{
		if (i == 0)
		{
			p_count = ft_strlen(grid[i]);
			i++;
			continue ;
		}
		c_count = ft_strlen(grid[i]);
		if (c_count != p_count)
			return (0);
		p_count = c_count;
		c_count = 0;
		i++;
	}
	return (1);
}

static int	check_wall(char **grid, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if ((i == 0 || i == (height - 1)) && grid[i][j] != '1')
				return (0);
			if ((j == 0 || j == (width - 1)) && grid[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_map *map)
{
	char	**grid;

	grid = map->map;
	if (valid_char(grid) == 0)
		return (0);
	if (check_rect(grid) == 0)
		return (0);
	if (check_wall(grid, map->height, map->width) == 0)
		return (0);
	return (1);
}
