#include "so_long.h"
/*
void	check_map_contents(char *argv[])
{
	check_is_rectangular(argv);
	check_is_closed(argv);
	check_is_exit(argv);
	check_is_collectible(argv);
	check_is_start(argv);
	check_is_nothing_more(argv);
}
*/
void	check_ptr(void *ptr)
{
	if (ptr == NULL)
	{
		printf("Null ptr error\n");
		exit(EXIT_FAILURE);
	}
}

void	check_num_args(int argc)
{
	if (argc != 2)
	{
		printf("Must recieve 1 arg\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

int	check_open(char *argv[])
{
	int	rtn;

	rtn = open(argv[1], O_RDONLY);
	if (rtn < 0)
	{
		perror("Open error");
		exit(EXIT_FAILURE);
	}
	return (rtn);
}

void	check_input(int argc, char *argv[])
{
	int		fd;
	int		i;
	char	*buf;

	i = 0;
	(void)argc;
	check_num_args(argc);
	buf = malloc(MAP_SIZE);
	check_ptr(buf);
	fd = check_open(argv);
	while (read(fd, &buf[i], 1))
		i++;
	printf("%s\n", buf);
	/*
	check_num_args(argc);
	check_map_extension(argv);
	check_map_contents(argv);
	*/
}
