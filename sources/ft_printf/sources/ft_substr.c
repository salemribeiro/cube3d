/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:00:03 by sfreitas          #+#    #+#             */
/*   Updated: 2020/05/08 14:13:59 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*valuesb;
	size_t	tlen;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tlen = ft_strlen(s);
	if (tlen < start)
		return (ft_strdup(""));
	if (tlen < (start + len))
		len = (tlen - start);
	valuesb = (char*)malloc((sizeof(char) * len) + 1);
	if (!valuesb)
		return (NULL);
	i = start;
	while (j < len)
		valuesb[j++] = s[i++];
	valuesb[j] = '\0';
	return (valuesb);
}
