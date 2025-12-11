/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haya <haya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:26:07 by haya              #+#    #+#             */
/*   Updated: 2025/12/11 21:22:20 by haya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "unistd.h"
# include "fcntl.h"

struct s_map {
    int width;
    int height;
    char **map;
} t_map;


int validate_map(char *filename);

#endif