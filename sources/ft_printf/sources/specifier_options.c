/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:57:57 by sfreitas          #+#    #+#             */
/*   Updated: 2020/12/01 09:06:42 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_parameters(char specifier, char *jmp, char *tmp)
{
	jmp = flag_options(tmp, specifier);
	jmp = width_options(jmp);
	jmp = precision_options(jmp);
	jmp = length_options(jmp);
	g_opt.specifier = specifier;
	return (jmp);
}

int		specifier_options(char *subtext)
{
	size_t	i;
	size_t	j;
	char	*jmp;
	char	*tmp;

	i = 1;
	j = 0;
	jmp = NULL;
	tmp = NULL;
	while (subtext[i])
	{
		while (SPECIFIERS[j] && subtext[i] != SPECIFIERS[j])
			j++;
		if (SPECIFIERS[j])
		{
			tmp = ft_substr(subtext, 1, i);
			jmp = get_parameters(SPECIFIERS[j], jmp, tmp);
			free(tmp);
			return (i + 1);
		}
		j = 0;
		i++;
	}
	return (0);
}
