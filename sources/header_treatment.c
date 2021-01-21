# include "cub3d.h"
# include "libft.h"

static int	get_resolution(const char *line)
{
	char **word;

	word = ft_split(line, ' ');
	if (!word[1] || !word[2])
		message_err(RESOLUTION_ERRO);
	g_header.resolution[0] = ft_atoi(word[1]);
	g_header.resolution[1] = ft_atoi(word[2]);
	return (SUCCESS);
}

static int	get_texture(const char *line)
{
	char **word;

	word = ft_split(line, ' ');
	if (!word[1])
		message_err(TEXTURE_EMPTY);
	if (!ft_strncmp(word[0], "NO", 2))
		g_header.nor_texture = word[1];
	else if (!ft_strncmp(word[0], "SO", 2))
		g_header.sou_texture = word[1];
	else if (!ft_strncmp(word[0], "WE", 2))
		g_header.wes_texture = word[1];
	else if (!ft_strncmp(word[0], "EA", 2))
		g_header.eas_texture = word[1];
	else if (!ft_strncmp(word[0], "S", 1))
		g_header.spr_texture = word[1];
	return(0);
}

static int	get_color(const char *line)
{
	char **word;
	char **color;

	word = ft_split(line, ' ');
	color = ft_split(word[1], ',');
	if (!color[0] || !color[1] || !color[2])
		message_err(INCORRECT_COLOR);
	if (!ft_strncmp(word[0], "C", 1))
	{
		g_header.ce_color[0] = ft_atoi(color[0]);
		g_header.ce_color[1] = ft_atoi(color[1]);
		g_header.ce_color[2] = ft_atoi(color[2]);
	}
	else if (!ft_strncmp(word[0], "F", 1))
	{
		g_header.fl_color[0] = ft_atoi(color[0]);
		g_header.fl_color[1] = ft_atoi(color[1]);
		g_header.fl_color[2] = ft_atoi(color[2]);
	}
	return(0);
}

int			get_header(const char *line)
{
	if (ft_strlen(line))
	{
		if (line[0] == 'R')
			get_resolution(line);
		else if (line[0] == 'N' && line[1] == 'O')
			get_texture(line);
		else if (line[0] == 'S' && line[1] == 'O')
			get_texture(line);
		else if (line[0] == 'W' && line[1] == 'E')
			get_texture(line);
		else if (line[0] == 'E' && line[1] == 'A')
			get_texture(line);
		else if (line[0] == 'S')
			get_texture(line);
		else if (line[0] == 'C')
			get_color(line);
		else if (line[0] == 'F')
			get_color(line);
	}
	return(0);
}