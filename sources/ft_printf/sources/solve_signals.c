/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 22:17:18 by salem             #+#    #+#             */
/*   Updated: 2020/12/01 15:32:59 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*solve_signal(char *ptr, int signal)
{
	char *tmp;

	tmp = ptr;
	if (signal == -1)
	{
		ptr = ft_strjoin("-", ptr);
		free(tmp);
	}
	else if ((g_opt.flags & PLUS) == PLUS && ptr[0] != '+' && ptr[0] != ' ')
	{
		ptr = ft_strjoin("+", ptr);
		free(tmp);
	}
	else if ((g_opt.flags & SPACE) == SPACE && ptr[0] != '+' && ptr[0] != ' ')
	{
		ptr = ft_strjoin(" ", ptr);
		free(tmp);
	}
	return (ptr);
}
