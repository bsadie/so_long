#include "so_long.h"

int	action_Esq(t_so_long *memory)
{
	(void)memory;
	printf("ESC termination\n");
	exit(EXIT_FAILURE);
	return (0);
}

void	action_A(t_so_long *memory)
{
	char	**map;
	int		i;
	int		j;

	i = memory->player_i;
	j = memory->player_j;
	map = memory->map_as_array;
	if (map[i][j - 1] == '0' || map[i][j - 1] == 'C')
	{
		if (map[i][j - 1] == 'C')
			memory->collect_count--;
		map[i][j - 1] = 'P';
		map[i][j] = '0';
		memory->player_j--;
		action_steps(memory);
	}
	else if (map[i][j - 1] == 'E')
	{
		if (memory->collect_count == 0)
			action_success(memory);
	}
}

void	action_W(t_so_long *memory)
{
	char	**map;
	int		i;
	int		j;

	i = memory->player_i;
	j = memory->player_j;
	map = memory->map_as_array;
	if (map[i - 1][j] == '0' || map[i - 1][j] == 'C')
	{
		if (map[i - 1][j] == 'C')
			memory->collect_count--;
		map[i - 1][j] = 'P';
		map[i][j] = '0';
		memory->player_i--;
		action_steps(memory);
	}
	else if (map[i - 1][j] == 'E')
	{
		if (memory->collect_count == 0)
			action_success(memory);
	}
}

void	action_D(t_so_long *memory)
{
	char	**map;
	int		i;
	int		j;

	i = memory->player_i;
	j = memory->player_j;
	map = memory->map_as_array;
	if (map[i][j + 1] == '0' || map[i][j + 1] == 'C')
	{
		if (map[i][j + 1] == 'C')
			memory->collect_count--;
		map[i][j + 1] = 'P';
		map[i][j] = '0';
		memory->player_j++;
		action_steps(memory);
	}
	else if (map[i][j + 1] == 'E')
	{
		if (memory->collect_count == 0)
			action_success(memory);
	}
}

void	action_S(t_so_long *memory)
{
	char	**map;
	int		i;
	int		j;

	i = memory->player_i;
	j = memory->player_j;
	map = memory->map_as_array;
	if (map[i + 1][j] == '0' || map[i + 1][j] == 'C')
	{
		if (map[i + 1][j] == 'C')
			memory->collect_count--;
		map[i + 1][j] = 'P';
		map[i][j] = '0';
		memory->player_i++;
		action_steps(memory);
	}
	else if (map[i + 1][j] == 'E')
	{
		if (memory->collect_count == 0)
			action_success(memory);
	}
}
