/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <sfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:10:42 by salem             #+#    #+#             */
/*   Updated: 2021/04/03 17:51:25 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "ft_printf.h"

static int	get_player(char **map)
{
	int		i;
	int		j;
	char	vs;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			check_caracter(map[i][j]);
			vs = map[i][j];
			if (vs == 'N' || vs == 'S' || vs == 'E' || vs == 'W')
			{
				if (g_world.vision)
					message_err(MUCH_PLAYERS);
				g_world.vision = vs;
				g_world.player[0] = i;
				g_world.player[1] = j;
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static char	**create_new_matriz(int y, int x)
{
	char	**map;
	int		i;
	int		j;
	int		len;

	i = 0;
	map = (char**)ft_calloc(sizeof(char*), y + 1);
	while (i < (y - 1))
	{
		j = 0;
		map[i] = (char*)ft_calloc(sizeof(char), x + 1);
		len = ft_strlen(g_map[i]);
		while (j < x)
		{
			map[i][j] = j < len ? g_map[i][j] : ' ';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	clear_pointer(g_map);
	return (map);
}

int			normalize_map(char **map)
{
	int x;
	int y;
	int value;

	x = 0;
	y = 0;
	value = 0;
	while (map[y])
	{
		value = ft_strlen(map[y]);
		if (value > x)
			x = value;
		y++;
	}
	if (y > 0)
	{
		g_world.lines = y;
		g_world.columns = x;
		y++;
		g_world.map = create_new_matriz(y, x);
	}
	else
		message_err(MAP_EMPTY);
	get_player(g_world.map);
	return (SUCCESS);
}
