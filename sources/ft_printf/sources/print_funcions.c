/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:46:59 by salem             #+#    #+#             */
/*   Updated: 2020/11/29 13:27:47 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printstr(char *text, int size)
{
	g_opt.count += (int)write(1, &text[0], size);
	return (size);
}

int		create_buffer(void)
{
	int i;

	i = 0;
	while (i < 2048)
		g_opt.text[i++] = '\0';
	return (0);
}
