#include "so_long.h"

int	key_hook(int keycode, t_so_long *memory)
{
	char	**map;
	int		i;
	int		j;

	(void)keycode;
	i = memory->player_i;
	j = memory->player_j;
	map = memory->map_as_array;
	if (keycode == 53)
		action_Esq(memory);
	if (keycode == 0)
		action_A(memory);
	if (keycode == 1)
		action_S(memory);
	if (keycode == 2)
		action_D(memory);
	if (keycode == 13)
		action_W(memory);
	return (0);
}

void	action_steps(t_so_long *memory)
{
	memory->steps_count++;
	printf("You did %d steps \n", memory->steps_count);
}

int	action_cross(t_so_long *memory)
{
	(void)memory;
	printf("Cross termination\n");
	exit(EXIT_FAILURE);
	return (0);
}

void	action_success(t_so_long *memory)
{
	(void)memory;
	printf("Mission complete\n");
	exit(EXIT_SUCCESS);
}
