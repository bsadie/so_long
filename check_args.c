#include "so_long.h"

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

int	check_and_open(char *argv[])
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

void	check_args(int argc, char *argv[])
{
	int	i;

	check_num_args(argc);
	i = ft_strlen(argv[1]);
	if (i > 4)
	{
		if (argv[1][i - 1] == 'r' && \
			argv[1][i - 2] == 'e' && \
			argv[1][i - 3] == 'b' && \
			argv[1][i - 4] == '.')
			return ;
		else
		{
			printf("File name error\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("File name error\n");
		exit(EXIT_FAILURE);
	}
}
