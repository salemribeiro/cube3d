/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 13:18:40 by salem             #+#    #+#             */
/*   Updated: 2020/11/28 21:32:01 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_char(char c)
{
	char	*tmp;
	int		width;

	tmp = NULL;
	width = g_opt.width;
	if (width > 1)
	{
		tmp = manager_value(ft_strdup(""), width - 1, ' ');
		if ((g_opt.flags & MINUS) == MINUS)
		{
			message_buffer(c);
			send_buffer(tmp);
		}
		else
		{
			send_buffer(tmp);
			message_buffer(c);
		}
	}
	else
		message_buffer(c);
	if (tmp)
		free(tmp);
}

void	store_percent(int width, char flags)
{
	char	*tmp;

	tmp = NULL;
	if (width > 0)
	{
		if ((flags & ZERO) != ZERO)
			tmp = manager_value(ft_strdup(""), width - 1, ' ');
		else
			tmp = manager_value(ft_strdup(""), width - 1, '0');
		if ((flags & MINUS) != MINUS)
			send_buffer(tmp);
		message_buffer('%');
		if ((flags & MINUS) == MINUS)
			send_buffer(tmp);
		if (tmp)
			free(tmp);
	}
	else
		message_buffer('%');
}
