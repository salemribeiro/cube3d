/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <salem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:11:22 by salem             #+#    #+#             */
/*   Updated: 2021/04/01 23:13:37 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
