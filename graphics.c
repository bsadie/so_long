#include "so_long.h"

void	init_graphics(t_so_long *memory)
{
	t_vars	*vars;
	t_data	*img;
	int		i;
	int		j;

	i = memory->map_lines;
	j = memory->map_collumns;
	memory->vars = malloc(sizeof(t_vars));
	vars = memory->vars;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, j * CS, i * CS, \
	"so_long");
	memory->img = malloc(sizeof(t_data));
	img = memory->img;
	img->img = mlx_new_image(vars->mlx, j * CS, i * CS);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
	&(img->line_length), &(img->endian));
	memory->textures = malloc(sizeof(t_imgs));
}

void	load_graphics(t_so_long *memory)
{
	t_vars	*vars;
	t_imgs	*imgs;
	int		img_size;

	imgs = memory->textures;
	img_size = 64;
	vars = memory->vars;
	imgs->wall = mlx_xpm_file_to_image(vars->mlx, "./textures/wall.xpm", \
	&img_size, &img_size);
	imgs->player = mlx_xpm_file_to_image(vars->mlx, "./textures/player.xpm", \
	&img_size, &img_size);
	imgs->collect = mlx_xpm_file_to_image(vars->mlx, "./textures/collect.xpm", \
	&img_size, &img_size);
	imgs->exit = mlx_xpm_file_to_image(vars->mlx, "./textures/exit.xpm", \
	&img_size, &img_size);
	imgs->floor = mlx_xpm_file_to_image(vars->mlx, "./textures/floor.xpm", \
	&img_size, &img_size);
}

void	display_map_norm(t_so_long *memory, int i, int j)
{
	t_vars	*vars;
	t_imgs	*imgs;

	imgs = memory->textures;
	vars = (memory->vars);
	if (memory->map_as_array[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, imgs->wall, \
		j * CS, i * CS);
	if (memory->map_as_array[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, imgs->floor, \
		j * CS, i * CS);
	if (memory->map_as_array[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, imgs->collect, \
		j * CS, i * CS);
	if (memory->map_as_array[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, imgs->exit, \
		j * CS, i * CS);
	if (memory->map_as_array[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, imgs->player, \
		j * CS, i * CS);
}

int	display_map(t_so_long *memory)
{
	t_vars	*vars;
	t_imgs	*imgs;
	int		i;
	int		j;

	imgs = memory->textures;
	vars = (memory->vars);
	i = 0;
	j = 0;
	while (i < memory->map_lines)
	{
		j = 0;
		while (j < memory->map_collumns)
		{
			display_map_norm(memory, i, j);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

void	display_graphics(t_so_long *memory)
{
	t_vars	*vars;

	vars = (memory->vars);
	load_graphics(memory);
	mlx_loop_hook(vars->mlx, display_map, memory);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, memory);
	mlx_hook(vars->win, 17, 1L << 17, action_cross, memory);
	mlx_loop(vars->mlx);
}
