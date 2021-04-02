/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <salem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:11:26 by salem             #+#    #+#             */
/*   Updated: 2021/04/01 23:12:36 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		clear_pointer(char **p)
{
	int i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (SUCCESS);
}

void	clear_header(void)
{
	free(g_header.nor_texture);
	free(g_header.sou_texture);
	free(g_header.wes_texture);
	free(g_header.eas_texture);
	free(g_header.spr_texture);
	return ;
}
