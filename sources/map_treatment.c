/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <salem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:10:35 by salem             #+#    #+#             */
/*   Updated: 2021/03/27 12:10:37 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_up(char **map, int y, int x)
{
	char value;
	int i;

	i = y;
	while(i >= 0)
	{
		value = map[i][x];
		if (value == ' ')
			message_err(INVALID_MAP);
		else if (value == '1')
			return (SUCCESS);
		i--;
	}
	return(SUCCESS);
}
static int check_down(char **map, int y, int x)
{
	char value;
	int i;

	i = y;
	while(i < g_world.lines)
	{
		value = map[i][x];
		if (value == ' ')
			message_err(INVALID_MAP);
		else if (value == '1')
			return(SUCCESS);
		i++;
	}
	return(SUCCESS);
}
static int check_left(char **map, int y, int x)
{
	char value;
	int i;

	i = x;
	while(i >= 0)
	{
		value = map[y][i];
		if (value == ' ')
			message_err(INVALID_MAP);
		else if (value == '1')
			return(SUCCESS);
		i--;
	}
	return(SUCCESS);
}
static int check_right(char **map, int y, int x)
{
	char value;
	int i;

	i = x;
	while(i < g_world.columns)
	{
		value = map[y][i];
		if (value == ' ')
			message_err(INVALID_MAP);
		else if (value == '1')
			return(SUCCESS);
		i++;
	}
	return(SUCCESS);
}

int			check_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if(map[i][j] == '0')
			{
				check_up(map, i, j);
				check_down(map, i, j);
				check_left(map, i, j);
				check_right(map, i, j);
			}
			j++;
		}
		i++;
	}
	return(SUCCESS);
}