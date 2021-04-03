/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <sfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:11:02 by salem             #+#    #+#             */
/*   Updated: 2021/04/03 14:34:24 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		check_caracter(char c)
{
	if (c != '0' && c != '1' && c != '2' && c != ' ' &&
		c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '\0')
		message_err(INCORRECT_MAP);
	return (SUCCESS);
}

char	**change_matriz(char **map, char *line, int count_line)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char**)ft_calloc(sizeof(char*), (count_line + 1));
	while (i < count_line)
	{
		tmp[i] = map[i];
		i++;
	}
	tmp[i] = line;
	free(map);
	return (tmp);
}

int		get_map(char *line)
{
	int	i;

	i = 0;
	if (!g_count_line)
	{
		if (ft_strlen(line))
		{
			g_map = (char**)ft_calloc(sizeof(char*), 1);
			g_map[0] = ft_strdup(line);
			g_count_line++;
		}
	}
	else
	{
		check_caracter(line[0]);
		g_map = change_matriz(g_map, ft_strdup(line), g_count_line);
		g_count_line++;
	}
	return (SUCCESS);
}
