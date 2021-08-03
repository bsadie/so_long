#include "so_long.h"

void	check_is_rectangular(char *map)
{
	int	k;
	int	i;
	int	cur_ox;
	int	prev_ox;

	i = 0;
	k = 1;
	prev_ox = ft_strlen_n(&map[i]);
	while (map[i + prev_ox + 1])
	{
		i += prev_ox + 1;
		cur_ox = ft_strlen_n(&map[i]);
		if (prev_ox != cur_ox)
		{
			printf("Map is not rectangular\n");
			exit(EXIT_FAILURE);
		}
		prev_ox = cur_ox;
	}
}
