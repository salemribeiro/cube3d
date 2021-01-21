/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:12:08 by sfreitas          #+#    #+#             */
/*   Updated: 2020/05/08 00:01:50 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			contador(const char *ptr)
{
	int i;

	i = 0;
	while (ptr[i] != '\0')
		i++;
	return (i);
}

static char			*execjoin(char const *s1, char const *s2, char *ptr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	i = contador(s1);
	j = contador(s2);
	ptr = (char*)malloc(sizeof(char) * (i + j + 1));
	if (!ptr)
		return (0);
	execjoin(s1, s2, ptr);
	return (ptr);
}
