/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:55:37 by sfreitas          #+#    #+#             */
/*   Updated: 2021/01/20 01:37:06 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

#define SUCCESS 0

enum	e_erros
{
	ARGUMENT,
	SOURCE_NFOUND,
	OPEN_FILE,
	READ_FILE,
	READ_NCOMPLETED,
	RESOLUTION_ERRO,
	TEXTURE_EMPTY,
	INCORRECT_COLOR
};

struct s_header
{
	int		resolution[2];
	char	*nor_texture;
	char	*sou_texture;
	char	*wes_texture;
	char	*eas_texture;
	char	*spr_texture;
	int		ce_color[3];
	int		fl_color[3];
} g_header;

int read_file(const char *source);
int message_err(const int err_number);
int	get_header(const char *line);

#endif
