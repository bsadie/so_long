#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_so_long	*memory;


	memory = init_memory();
	read_and_check_input(argc, argv, memory);
	convert_map_line_to_array(memory);
	count_lines_and_collumns(memory);
	//printf("%d, %d \n", memory->map_lines, memory->map_collumns);
	//printf("%s\n", (memory->map_as_array)[]);
	//graphics_experience();
}

