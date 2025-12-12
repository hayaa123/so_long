#include "so_long.h"

int return_error(char *msg, int code)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(msg, 2);
    return (code);
}

int main(int argc, char **argv)
{
    char *content;
    if(argc != 2)
        return return_error("The programm takes 1 parameter\n", 1);
    content = read_as_line(argv[1]);
    if(!content)
    {
        free(content);
        return return_error("Somthing went wrong", 2);
    }
    if(validate_map(content) == 0)
    {
        free(content);
        return return_error("Invalid map", 3);
    }
    return (0);
}