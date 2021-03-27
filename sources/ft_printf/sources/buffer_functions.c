/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:47:21 by sfreitas          #+#    #+#             */
/*   Updated: 2020/12/01 09:02:36 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_buffer(char c, char *buffer, int size)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_calloc(size + 2, sizeof(c));
	if (buffer)
	{
		while (buffer[i])
		{
			tmp[i] = buffer[i];
			i++;
		}
		free(buffer);
	}
	tmp[i] = c;
	return (tmp);
}

int		message_buffer(int c)
{
	static int	i;

	if (i >= 2048 || c == END_TEXT)
	{
		if (c != END_TEXT)
		{
			g_opt.text[i] = (char)c;
			ft_printstr(g_opt.text, ++i);
		}
		else
			ft_printstr(g_opt.text, i);
		i = 0;
		return (0);
	}
	else if (i < 2048)
		g_opt.text[i] = (char)c;
	g_opt.nprint = i + 1;
	i++;
	return (0);
}

void	send_buffer(char *text)
{
	int i;

	i = 0;
	while (text[i])
		message_buffer((int)text[i++]);
}

void	clear_struct(char print)
{
	int i;

	i = 0;
	g_opt.flags = 0;
	g_opt.width = 0;
	g_opt.precision = 0;
	g_opt.length = 0;
	g_opt.specifier = 0;
	g_opt.nprint = 0;
	if (print)
	{
		while (i < 2048)
			g_opt.text[i++] = '\0';
		g_opt.count = 0;
	}
}
