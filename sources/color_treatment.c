#include "cub3d.h"

int			check_rgb(int *color)
{
	int i;

	i = 0;
	while(i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			return(INCORRECT_COLOR);
		i++;
	}
	return(SUCCESS);
}