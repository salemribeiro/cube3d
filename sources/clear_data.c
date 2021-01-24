#include "cub3d.h"

int			clear_pointer(char **p)
{
	int i;

	i = 0;
	while(p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (SUCCESS);
}

void		clear_header()
{
	free(g_header.nor_texture);
	free(g_header.sou_texture);
	free(g_header.wes_texture);
	free(g_header.eas_texture);
	free(g_header.spr_texture);
}