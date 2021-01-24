/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 02:57:18 by salem             #+#    #+#             */
/*   Updated: 2021/01/20 03:00:14 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	verify_line(const char *line)
{
	int i;

	i = 0;
	while(line[i])
	{
		if(line[i] != ' ' && line[i] != '\n')
			message_err(INVALID_HEADER);
			i++;
	}
	return ;
}

int		message_err(const int err_number)
{
	printf("Error\n%s\n", g_errors[err_number]);
	exit(1);
}
