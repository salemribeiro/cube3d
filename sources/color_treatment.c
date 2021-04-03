/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <sfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:11:22 by salem             #+#    #+#             */
/*   Updated: 2021/04/03 17:28:48 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		check_rgb(int *color)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			return (INCORRECT_COLOR);
		i++;
	}
	return (SUCCESS);
}

void	add_color(char **color, char option)
{
	if (option == 'C')
	{
		g_header.ce_color[0] = ft_atoi(color[0]);
		g_header.ce_color[1] = ft_atoi(color[1]);
		g_header.ce_color[2] = ft_atoi(color[2]);
	}
	else
	{
		g_header.fl_color[0] = ft_atoi(color[0]);
		g_header.fl_color[1] = ft_atoi(color[1]);
		g_header.fl_color[2] = ft_atoi(color[2]);
	}
	return ;
}
