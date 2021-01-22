#include "cub3d.h"
#include "libft.h"


char	**change_matriz(char **map, char *line, int count_line)
{
	char **tmp;
	int i;

	i = 0;
	tmp = (char**)ft_calloc(sizeof(char*), (count_line + 1));
	while (i < count_line)
	{
		tmp[i] = map[i];
		i++;
	}
	tmp[i] = line;
	free(map);
	return(tmp);
}

int get_map(char *line)
{
	int			i;
	
	i = 0;
	if (line[0] != '0' && line[0] != '1' && line[0] != '2' && line[0] != ' ' &&
		line[0] != 'N' && line[0] != 'S' && line[0] != 'E' && line[0] != 'W')
	return (0);
	if (!g_count_line)
	{
		g_map = (char**)ft_calloc(sizeof(char*), 1);
		g_map[0] = ft_strdup(line);
	}
	else
		g_map = change_matriz(g_map, ft_strdup(line), g_count_line);
	g_count_line++;
	return(SUCCESS);
}