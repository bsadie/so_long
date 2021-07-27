#include "so_long.h"

char	*read_map_to_str(int fd)
{
	int		read_bytes;
	char	*map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	read_bytes = 1;
	map = malloc(MAP_SIZE);
	check_ptr(map);
	while (read_bytes)
	{
		read_bytes = read(fd, &map[i], 1);
		if (map[i] == '\n')
			j++;
		i++;
	}
	map[i - 1] = '\0';
	return (map);
}

void	check_input(int argc, char *argv[])
{
	int		fd;
	char	*map;

	check_args(argc, argv);
	fd = check_and_open(argv);
	map = read_map_to_str(fd);
	write(1, map, ft_strlen(map));
	check_map_contents(map);

}
