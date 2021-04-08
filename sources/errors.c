/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <sfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 02:57:18 by salem             #+#    #+#             */
/*   Updated: 2021/04/07 00:17:07 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"

void	verify_line(const char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			message_err(INVALID_HEADER);
		i++;
	}
	return ;
}

int		message_err(const int err_number)
{
	ft_printf("Error\n%s\n", g_errors[err_number]);
	exit(err_number);
}
