#include "so_long.h"

void	check_is_closed_top(char *map)
{
	int	map_len;
	int	str_len;
	int	i;
	//int	j;
	//int	str_count;

	map_len = ft_strlen(map);
	str_len = ft_strlen_n(map);
	i = 0;
	//j = 0;
	//str_count = map_len / (str_len + 1);
	while (i < str_len)
	{
		if (map[i] != '1')
		{
			printf("Map is not closed: top line\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}

}

void	check_is_closed_left(char *map)
{
	int	map_len;
	int	str_len;
	int	i;
	int	j;
	int	str_count;

	map_len = ft_strlen(map);
	str_len = ft_strlen_n(map);
	i = 0;
	j = 0;
	str_count = map_len / (str_len + 1);
	while (j < str_count)
	{
		if (map[i] != '1')
		{
			printf("Map is not closed: left line\n");
			exit(EXIT_FAILURE);
		}
		j++;
		i += str_len + 1;
	}
}

void	check_is_closed_right(char *map)
{
	int	map_len;
	int	str_len;
	int	i;
	int	j;
	int	str_count;

	map_len = ft_strlen(map);
	str_len = ft_strlen_n(map);
	i = 0;
	j = 0;
	str_count = map_len / (str_len + 1);
	i = str_len - 1;
	j = 0;
	while (j < str_count)
	{
		if (map[i] != '1')
		{
			printf("Map is not closed: right line\n");
			exit(EXIT_FAILURE);
		}
		j++;
		i += str_len + 1;
	}
}

void	check_is_closed_bottom(char *map)
{
	int	map_len;
	int	str_len;
	int	i;
	int	j;
	int	str_count;

	map_len = ft_strlen(map);
	str_len = ft_strlen_n(map);
	i = 0;
	j = 0;
	str_count = map_len / (str_len + 1);
	i = (str_len + 1) * (str_count - 1);
	while (map[i] != '\n')
	{
		if (map[i] != '1')
		{
			printf("Map is not closed: bottom line\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_is_closed(char *map)
{
	check_is_closed_top(map);
	check_is_closed_left(map);
	check_is_closed_right(map);
	check_is_closed_bottom(map);
}