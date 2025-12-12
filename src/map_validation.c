#include "so_long.h"

int valid_char(char *content)
{
    int i;
    int exit;
    int start;
    int collect;

    i = 0;
    exit =0;
    start =0;
    collect =0;
    while (content[i])
    {
        if(content[i] == 'P')
            start++;
        else if(content[i] == 'E')
            exit++;
        else if(content[i] == 'C')
            collect++;
        else if (content[i] != '\n' && content[i] != '1' && content[i] != '0')
            return (0);
        i++;
    }
    if(start != 1 || exit != 1 || collect < 1)
        return (0);
    return (1);
}

int check_rect(char *content)
{
    int i;
    int line;
    int p_count;
    int c_count;

    i = 0;
    line = 0;
    p_count = 0;
    c_count = 0;
    while (content[i])
    {
        if(content[i] == '\n' || content[i] == '\0')
        {
            if(line != 0 && p_count != c_count)
                return (0);
            p_count = c_count;
            c_count = 0;
            line++;
            i++;
            continue;
        }
        c_count++;
        i++;
    }
    return (1);
}

int count_lines(char *content)
{
    int i;
    int line_count;

    i = 0;
    line_count = 0;
    while(content[i])
    {
         if(content[i + 1] == '\n' || content[i + 1] == '\0')
         {
            line_count++;
         }
        i++;
    }
    return (line_count);
}

int check_wall(char *content)
{
    int i;
    int line;
    int line_count;

    i = 0;
    line = 1;
    line_count = count_lines(content);
    while (content[i])
    {
        if(content[i + 1] == '\n' || content[i + 1] == '\0')
        {
            if(content[i] != '1')
                return (0);
            if(content[i + 1] == '\n' && content[i + 2] != '1')
                    return (0);
            line++;
            i = i + 2;
            continue;
        }
        if (line == 1 || line == line_count)
            if (content[i] != '1')
                return (0);
        i++;
    }
    return (1);
}

int validate_map(char *content)
{
    if(valid_char(content) == 0)
        return (0);
    if(check_rect(content) == 0)
        return (0);
    if(check_wall(content) == 0)
        return (0);
    return (1);
}
