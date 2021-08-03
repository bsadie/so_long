#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_so_long	*memory;

	memory = init_memory();
	read_and_check_input(argc, argv, memory);
	convert_map_line_to_array(memory);
	count_lines_and_collumns(memory);
	find_player_position(memory);
	count_collectibles(memory);
	init_graphics(memory);
	display_graphics(memory);
}
