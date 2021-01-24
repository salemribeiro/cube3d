#include "cub3d.h"

int main(int argc, char *argv[])
{
    if (argc == 1 || argc > 3)
        message_err(ARGUMENT);
    read_file(argv[1]);
	normalize_map(g_map);
	check_map(g_world.map);
	clear_pointer(g_world.map);
	clear_header();
    return(0);
}