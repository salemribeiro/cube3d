/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/12/01 09:19:30 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_options(char *parameters, char specifier)
{
	char	flags;

	flags = 0;
	while (*parameters == '+' || *parameters == '-' || *parameters == '#' ||
			*parameters == '0' || *parameters == ' ')
	{
		flags = (*parameters == '+') ? flags | PLUS : flags;
		flags = (*parameters == '-') ? flags | MINUS : flags;
		flags = (*parameters == '#') ? flags | HASH : flags;
		flags = (*parameters == '0') ? flags | ZERO : flags;
		flags = (*parameters == ' ') ? flags | SPACE : flags;
		parameters++;
	}
	g_opt.flags = solve_incompatible(flags, specifier);
	return (parameters);
}

char	solve_incompatible(char flags, char specifier)
{
	if ((flags & PLUS) == PLUS && (flags & SPACE) == SPACE)
		flags = flags ^ SPACE;
	if ((flags & MINUS) == MINUS && (flags & ZERO) == ZERO)
		flags = flags ^ ZERO;
	flags = solve_plus(flags, specifier);
	flags = solve_minus(flags, specifier);
	flags = solve_hash(flags, specifier);
	flags = solve_zero(flags, specifier);
	flags = solve_space(flags, specifier);
	return (flags);
}
