#include "so_long.h"

t_so_long	*init_memory(void)
{
	t_so_long	*rtn;
	int	i;

	i = 0;
	rtn = malloc(sizeof(t_so_long));
	rtn->map_as_line = malloc(MAP_SIZE);
	rtn->map_as_array = malloc(MAP_SIZE_OY * sizeof(char *));
	while (i < MAP_SIZE_OY)
	{
		(rtn->map_as_array)[i] = malloc(MAP_SIZE_OX);
		i++;
	}
	rtn->map_collumns = 0;
	rtn->map_lines =0;
	return (rtn);

}