#include "so_long.h"

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

void	find_player_position(t_so_long *memory)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < memory->map_lines)
	{
		j = 0;
		while (j < memory->map_collumns)
		{
			if (memory->map_as_array[i][j] == 'P')
			{
				memory->player_i = i;
				memory->player_j = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	count_collectibles(t_so_long *memory)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = memory->map_as_array;
	while (i < memory->map_lines)
	{
		j = 0;
		while (j < memory->map_collumns)
		{
			if (map[i][j] == 'C')
				memory->collect_count++;
			j++;
		}
		i++;
	}
}
