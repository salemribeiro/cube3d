#include "cub3d.h"

int main(int argc, char *argv[])
{
    if (argc == 1 || argc > 3)
        message_err(ARGUMENT);
    read_file(argv[1]);
    return(0);
}