#include "so_long.h"

int valid_char(char *filename)
{
    char *buff = malloc(sizeof(char) + 1);
    int fd;
    int bytes_read;
    fd = open(filename, O_RDONLY);
    ft_printf("fd: %i\n",fd );

    buff[1] = '\0';
    while (1)
    {
        bytes_read = read(fd,buff,sizeof(char));
        if (bytes_read == 0 || bytes_read == -1)
            break;
        if (buff[0] != 'P' && buff[0] != 'E' && buff[0] != '\n'
            && buff[0] != 'C' && buff[0] != '1' && buff[0] != '0')
        {
            free(buff);
            close(fd);
            return (0);
        }
    }
    free(buff);
    close(fd);
    return (1);
}

int validate_map(char *filename)
{
    if(valid_char(filename) == 0)
        return (0);
    return (1);
}
