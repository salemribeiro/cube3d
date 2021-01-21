/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:55:37 by sfreitas          #+#    #+#             */
/*   Updated: 2020/04/29 22:56:35 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** FUNCAO PRINCIPAL
** Responsavel por executar a leitura das linhas de um arquivo, realizando
**  isto atraves de um loop, carregando os dados em pates discretas cujo o
**   tamanho e definido em tempo de compilacao atraves da flag "BUFFER_SIZE".
**        (gcc -Wall -Wextra -Wextra -D BUFFER_SIZE=70 -g *.c)
** As partes sao unidas formando uma linha e sua completude e definida apos a
**   obtencao do caracter '\ n'.
** O termino funcao e feito apos o encontro de um '\ n', '\ 0', erro ou fim de
**   arquivo "EOF".
** O objetivo principal do exercicio e o entendimento do modificador "static"
**   utilizado na persistencia de dados em memoria, treino com a biblioteca
**   de "IO" e o uso responsavel de alocacao de memoria.
** Este projeto mostra a dificuldade em lidar com as funcoes Malloc e Free.
*/

int			get_next_line(int fd, char **line)
{
	static char		*s_line;
	char			*l_buffer;
	register int	result;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	result = 1;
	*line = NULL;
	l_buffer = (char*)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!s_line)
		s_line = (char*)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (!check_line(s_line) && (result >= 1 && result <= BUFFER_SIZE))
	{
		result = read(fd, l_buffer, BUFFER_SIZE);
		if (result > 0 && result <= BUFFER_SIZE && s_line)
			s_line = ft_strjoin(s_line, l_buffer);
		ft_bzero(l_buffer);
	}
	if (result >= 0 && result <= BUFFER_SIZE)
		s_line = cleanline(line, s_line);
	free(l_buffer);
	if (result > 0 && result <= BUFFER_SIZE)
		return (1);
	return (result == 0 ? 0 : -1);
}

/*
** Funcao responsavel por unir as duas strings.
*/

char		*ft_strjoin(char *s1, char *s2)
{
	char			*ptr;
	register int	i;
	register int	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = (char*)ft_calloc(i + j + 1, sizeof(char));
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (ptr);
}

/*
** Funcao valida se existe uma linha completa, ele verifica se o \n ja esta
**   contido na funcao e retorna um inteiro verdadeiro ou falso.
*/

int			check_line(char *ptr)
{
	register int newline;
	register int i;

	newline = 0;
	i = 0;
	if (!ptr)
		return (1);
	while (ptr[i])
	{
		if (ptr[i] == '\n')
			newline = 1;
		i++;
	}
	return (newline);
}

/*
** Funcao responsavel por alocar memoria, foi modificada para retornar um
**   ponteiro de char e foi mesclada a funcao bzero, evitando assim  a
**   implementacao de mais uma funcao no arquivo.
*/

char		*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	register size_t	i;

	if (count > 1000000)
		count = 1000000;
	ptr = (char*)malloc(count * size);
	i = 0;
	if (ptr)
	{
		while (i < count)
		{
			ptr[i] = '\0';
			i++;
		}
	}
	return (ptr);
}

/*
** Funcao responsavel por copiar os dados de uma string para outra.
*/

size_t		ft_strlcpy(char *dest, char *src, size_t size)
{
	register size_t i;
	register size_t j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}
