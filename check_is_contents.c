#include "so_long.h"

void	check_is_exit(char *map)
{
	int	rtn;
	int	i;

	i = 0;
	rtn = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			rtn++;
		i++;
	}
	if (rtn != 1)
	{
		printf("Map has bad exit\n");
		exit(EXIT_FAILURE);
	}
}

void	check_is_collectible(char *map)
{
	int	rtn;
	int	i;

	i = 0;
	rtn = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			rtn++;
		i++;
	}
	if (rtn == 0)
	{
		printf("Map has no collectible\n");
		exit(EXIT_FAILURE);
	}
}

void	check_is_start(char *map)
{
	int	rtn;
	int	i;

	i = 0;
	rtn = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			rtn++;
		i++;
	}
	if (rtn != 1)
	{
		printf("Map has bad start\n");
		exit(EXIT_FAILURE);
	}
}

void	check_is_nothing_else(char *map)
{
	int	rtn;
	int	i;

	i = 0;
	rtn = 0;
	while (map[i])
	{
		if (map[i] != '0' && \
			map[i] != '1' && \
			map[i] != 'C' && \
			map[i] != 'E' && \
			map[i] != 'P' && \
			map[i] != '\n')
			rtn++;
		i++;
	}
	if (rtn != 0)
	{
		printf("Map has bad wrong symbols\n");
		exit(EXIT_FAILURE);
	}
}

void	check_map_contents(char *map)
{
	check_is_rectangular(map);
	check_is_closed(map);
	check_is_exit(map);
	check_is_collectible(map);
	check_is_start(map);
	check_is_nothing_else(map);
}
