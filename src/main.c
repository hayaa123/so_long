#include "so_long.h"

int main(int argc, char **argv)
{

    if(argc != 2)
        ft_putstr_fd("The programm takes 1 parameter\n",2);
    ft_printf("valid %i\n", validate_map(argv[1]));
}