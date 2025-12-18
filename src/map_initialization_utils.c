/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialization_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:15:22 by hal-lawa          #+#    #+#             */
/*   Updated: 2025/12/18 13:16:05 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	helper_print(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		ft_printf("%s\n", grid[i]);
		i++;
	}
}

int	calc_height(char *content)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	if (!content)
		return (0);
	while (content[i])
	{
		if (content[i + 1] == '\n' || content[i + 1] == '\0')
		{
			line++;
			if (content[i + 1] == '\n')
				i++;
			i++;
			continue ;
		}
		i++;
	}
	return (line);
}

int	calc_width(char *content)
{
	int	i;

	i = 0;
	if (!content)
		return (0);
	while (content[i])
	{
		if (content[i] == '\n' || content[i] == '\0')
			break ;
		i++;
	}
	return (i);
}
