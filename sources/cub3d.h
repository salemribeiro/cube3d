/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <salem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:55:37 by sfreitas          #+#    #+#             */
/*   Updated: 2021/04/01 23:16:03 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define SUCCESS 0

static char	g_errors[][50] =
{
	"number of arguments",
	"source is not found",
	"can not open file",
	"read file",
	"file was not read in full",
	"resolution is incorrect",
	"source for texture is empty",
	"incorrect value or invalid range for color",
	"map data error, information is not valid",
	"map is empty",
	"invalid file",
	"invalid header",
	"invalid texture",
	"your map must have only one player",
	"map is invalid"
};

enum		e_erros
{
	ARGUMENT,
	SOURCE_NFOUND,
	OPEN_FILE,
	READ_FILE,
	READ_NCOMPLETED,
	RESOLUTION_ERRO,
	TEXTURE_EMPTY,
	INCORRECT_COLOR,
	INCORRECT_MAP,
	MAP_EMPTY,
	INVALID_FILE,
	INVALID_HEADER,
	INVALID_TEXTURE,
	MUCH_PLAYERS,
	INVALID_MAP
};

char		**g_map;
int			g_count_line;
struct		s_header
{
	int		resolution[2];
	char	*nor_texture;
	char	*sou_texture;
	char	*wes_texture;
	char	*eas_texture;
	char	*spr_texture;
	int		ce_color[3];
	int		fl_color[3];
	char	full;
}			g_header;

struct		s_world
{
	char	**map;
	int		lines;
	int		columns;
	char	player[2];
	char	vision;
}			g_world;

int			read_file(const char *source);
int			message_err(const int err_number);
int			get_header(const char *line);
int			get_map(char *line);
int			clear_pointer(char **p);
void		clear_header();
char		**change_matriz(char **map, char *line, int count_line);
int			normalize_map(char **map);
void		verify_line(const char *line);
int			check_caracter(char c);
int			check_header();
int			check_map(char **map);
int			check_rgb(int color[]);

#endif
