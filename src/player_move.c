/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:32:41 by hal-lawa          #+#    #+#             */
/*   Updated: 2025/12/18 12:13:49 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	if (map->map[map->player->y - 1][map->player->x] == '1')
		return ;
	if (map->map[map->player->y - 1][map->player->x] == 'C')
		map->player->collect_count += 1;
	if (map->player->x == map->exit->x && map->player->y == map->exit->y)
		map->map[map->player->y][map->player->x] = 'E';
	else
		map->map[map->player->y][map->player->x] = '0';
	map->player->y -= 1;
	map->map[map->player->y][map->player->x] = 'P';
	map->p_moves++;
	ft_printf("Player_moves: %i\n", map->p_moves);
}

void	move_down(t_map *map)
{
	if (map->map[map->player->y + 1][map->player->x] == '1')
		return ;
	if (map->map[map->player->y + 1][map->player->x] == 'C')
		map->player->collect_count += 1;
	if (map->player->x == map->exit->x && map->player->y == map->exit->y)
		map->map[map->player->y][map->player->x] = 'E';
	else
		map->map[map->player->y][map->player->x] = '0';
	map->player->y += 1;
	map->map[map->player->y][map->player->x] = 'P';
	map->p_moves++;
	ft_printf("Player_moves: %i\n", map->p_moves);
}

void	move_left(t_map *map)
{
	if (map->map[map->player->y][map->player->x - 1] == '1')
		return ;
	if (map->map[map->player->y][map->player->x - 1] == 'C')
		map->player->collect_count += 1;
	if (map->player->x == map->exit->x && map->player->y == map->exit->y)
		map->map[map->player->y][map->player->x] = 'E';
	else
		map->map[map->player->y][map->player->x] = '0';
	map->player->x -= 1;
	map->map[map->player->y][map->player->x] = 'P';
	map->p_moves++;
	ft_printf("Player_moves: %i\n", map->p_moves);
}

void	move_right(t_map *map)
{
	if (map->map[map->player->y][map->player->x + 1] == '1')
		return ;
	if (map->map[map->player->y][map->player->x + 1] == 'C')
		map->player->collect_count += 1;
	if (map->player->x == map->exit->x && map->player->y == map->exit->y)
		map->map[map->player->y][map->player->x] = 'E';
	else
		map->map[map->player->y][map->player->x] = '0';
	map->player->x += 1;
	map->map[map->player->y][map->player->x] = 'P';
	map->p_moves++;
	ft_printf("Player_moves: %i\n", map->p_moves);
}
