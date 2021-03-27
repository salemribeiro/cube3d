/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_and_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/12/01 09:15:01 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	solve_plus(char flags, char specifier)
{
	int		i;
	int		valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = flags & PLUS;
	while (SPECIFIERS1[i])
	{
		if (SPECIFIERS1[i] == specifier)
			valid = 1;
		i++;
	}
	if (tmp == PLUS && valid == 1)
		flags = flags ^ PLUS;
	return (flags);
}

char	solve_minus(char flags, char specifier)
{
	int tmp;

	tmp = flags & MINUS;
	if (tmp == MINUS && specifier == 'n')
		flags = flags ^ MINUS;
	return (flags);
}

char	solve_hash(char flags, char specifier)
{
	int		i;
	char	valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = flags & HASH;
	while (SPECIFIERS2[i])
	{
		if (SPECIFIERS2[i] == specifier)
			valid = 1;
		i++;
	}
	if (tmp == HASH && valid == 1)
		flags = flags ^ HASH;
	return (flags);
}

char	solve_zero(char flags, char specifier)
{
	int		i;
	char	valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = flags & ZERO;
	while (SPECIFIERS3[i])
	{
		if (SPECIFIERS3[i] == specifier)
			valid = 1;
		i++;
	}
	if (tmp == ZERO && valid == 1)
		flags = flags ^ ZERO;
	return (flags);
}

char	solve_space(char flags, char specifier)
{
	int		i;
	char	valid;
	int		tmp;

	i = 0;
	valid = 0;
	tmp = flags & SPACE;
	while (SPECIFIERS1[i])
	{
		if (SPECIFIERS1[i] == specifier)
			valid = 1;
		i++;
	}
	if (tmp == SPACE && valid == 1)
		flags = flags ^ SPACE;
	return (flags);
}
