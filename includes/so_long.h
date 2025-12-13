/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haya <haya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:26:07 by haya              #+#    #+#             */
/*   Updated: 2025/12/13 18:21:15 by haya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "unistd.h"
# include "stdio.h"
#include <errno.h>
#include <string.h>
# include "fcntl.h"

typedef struct s_map {
    int width;
    int height;
    char **map;
} t_map;

char *read_as_line(char *filename);
int validate_map(t_map *map);
t_map *initialize_map(char *content);
int validate_path(t_map map);
void helper_print(char **grid); // @TODO: Remove it after finishing the project.
void free_map(t_map *map);

#endif