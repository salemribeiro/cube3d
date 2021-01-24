/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:24:43 by sfreitas          #+#    #+#             */
/*   Updated: 2020/02/27 16:15:25 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	while (*s1 && ft_strchr(s2, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(s2, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
