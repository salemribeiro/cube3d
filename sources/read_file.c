#include "cub3d.h"
#include "get_next_line.h"


static int	build_to_memory(int fd)
{
	int		ret;
	char	*line;

	ret = get_next_line(fd, &line);
	while(line)
	{
		get_header(line);
		printf("%s\n", line);
		free(line);
		if (ret <= 0)
			break;
		ret = get_next_line(fd, &line);
	}
	
	return(SUCCESS);
}

int read_file(const char *source)
{
    int	fd;

	fd = open(source, O_RDONLY);
	if(fd < 2)
		message_err(OPEN_FILE);
	build_to_memory(fd);
	return (SUCCESS);	
}