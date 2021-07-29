#include "so_long.h"

char	*read_map_to_str(int fd, t_so_long *memory)
{
	int		read_bytes;
	char	*map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	read_bytes = 1;
	map = memory->map_as_line;
//	map = malloc(MAP_SIZE);
//	check_ptr(map);
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

void	read_and_check_input(int argc, char *argv[], t_so_long *memory)
{
	int		fd;
	char	*map;

	map = memory->map_as_line;
	check_args(argc, argv);
	fd = check_and_open(argv);
	map = read_map_to_str(fd, memory);
	write(1, map, ft_strlen(map));
	check_map_contents(map);

}

void	convert_map_line_to_array(t_so_long *memory)
{
	int		i;
	int		j;
	int		k;
	char	**dst;
	char	*src;

	i = 0;
//	j = 0;
	k = 0;
	src = memory->map_as_line;
	dst = memory->map_as_array;
	while(k < ft_strlen(src))
	{
		j = 0;
		while(src[k] != '\n')
		{
			dst[i][j] = src[k];
			j++;
			k++;
		}
		dst[i][j] = '\0';
		k++;
		i++;
	}
	dst[i][0] = '\0';
}

void	count_lines_and_collumns(t_so_long *memory)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = memory->map_as_array;
	while (map[0][j])
		j++;
	while (map[i][0])
		i++;
	memory->map_collumns = j;
	memory->map_lines = i;
}
