/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_as_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-lawa <hal-lawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:43:22 by haya              #+#    #+#             */
/*   Updated: 2025/12/15 10:20:54 by hal-lawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *safe_strjoin(char *s1,char *s2)
{
    char *new;
    new = ft_strjoin(s1,s2);
    if (s1)  
        free(s1);
    return (new);
}

char *read_as_line(char *filename) 
{
    char *buff;
    char *line;
    int fd;
    int bytes_read;
   
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    buff = malloc(sizeof(char) + 1);
    if (!buff)
        return (NULL);
    buff[1] = '\0';
    line = NULL;
    while(1)
    {
        bytes_read = read(fd,buff, sizeof(char));
        if( bytes_read == 0 || bytes_read == -1)
            break;
        line = safe_strjoin(line, buff);
    }
    close(fd);
    free(buff);
    return (line);
}