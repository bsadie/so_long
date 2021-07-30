#include "so_long.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

int	ft_close(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	//mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_FAILURE);
	return (0);
}

void	ft_put_square(t_data *figure, int x_start, int y_start, int color)
{
	int	i;
	int	size;

	size = 50;

	i = y_start;
	while (i < size)
	{
		ft_mlx_pixel_put(figure, x_start, i, color);
		//color -= 100;
		i++;
	}
	i = x_start;
	while (i < size)
	{
		ft_mlx_pixel_put(figure, i, y_start, 0x001fffd2);
		i++;
	}

	i = y_start;
	while (i < size)
	{
		ft_mlx_pixel_put(figure, size, i, color);
		i++;
	}
	i = x_start;
	while (i < size)
	{
		ft_mlx_pixel_put(figure, i, size, color);
		i++;
	}

}



void	graphics_experience(void)
{
	//void	*mlx;
	//void	*mlx_win;
	t_vars	vars;
	t_data	img;
	void	*dragon;
	char	*path = "./images/dragon.xmp";
	int		dr_width;
	int		dr_height;


	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	ft_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	ft_mlx_pixel_put(&img, 6, 5, 0x00FF0000);
	ft_mlx_pixel_put(&img, 7, 5, 0x00FF0000);
	ft_mlx_pixel_put(&img, 8, 5, 0x00FF0000);
	ft_mlx_pixel_put(&img, 9, 5, 0x00FF0000);
	ft_mlx_pixel_put(&img, 1, 5, 0x00FF0000);
	ft_mlx_pixel_put(&img, 2, 5, 0x00FF0000);
	ft_mlx_pixel_put(&img, 3, 5, 0x00FF0000);
	ft_mlx_pixel_put(&img, 4, 5, 0x00FF0000);


	ft_put_square(&img, 10, 10, 0x00fff2a);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
//	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
//	mlx_loop_hook(vars.mlx, ft_put_square, )
	dragon = mlx_xpm_file_to_image(vars.mlx, path, &dr_width, &dr_height);


	mlx_loop(vars.mlx);
}

void	init_graphics(t_so_long *memory)
{
	t_vars	*vars;
	t_data	*img;
//	t_data	*floor;
	int		i;
	int		j;

	i = memory->map_lines;
	j = memory->map_collumns;

	memory->vars = malloc(sizeof(t_vars));
	vars = memory->vars;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, j * CELL_SIZE, i * CELL_SIZE, "so_long");

	memory->img = malloc(sizeof(t_data));
	img = memory->img;
	img->img = mlx_new_image(vars->mlx, j * CELL_SIZE, i * CELL_SIZE);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));

	memory->textures = malloc(sizeof(t_imgs));
//	memory->floor = malloc(sizeof(t_data));
//	floor = memory->floor;

}
/*
void	load_image(t_so_long *memory, t_data *img, char *path)
{
	int	size;
	size = CELL_SIZE;

	img->img = mlx_xpm_file_to_image(memory->vars->mlx, path, &size, &size);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
}

int	get_color(t_data *img, int i, int j)
{
	int		*rtn;
	//int		rtn;
	int		offset;

	offset = i * img->line_length + j * (img->bits_per_pixel / 8);
	rtn = (int *)(img->addr + offset);
	return (*rtn);
}
*/
void	load_graphics(t_so_long *memory)
{
	t_vars	*vars;
	t_imgs	*imgs;
	int		img_size;

	imgs = memory->textures;

	img_size = 64;
	vars = memory->vars;
	imgs->wall = mlx_xpm_file_to_image(vars->mlx, "./textures/wall.xpm", &img_size, &img_size);
	imgs->player = mlx_xpm_file_to_image(vars->mlx, "./textures/player.xpm", &img_size, &img_size);
	imgs->collect = mlx_xpm_file_to_image(vars->mlx, "./textures/collect.xpm", &img_size, &img_size);
	imgs->exit = mlx_xpm_file_to_image(vars->mlx, "./textures/exit.xpm", &img_size, &img_size);
	imgs->floor = mlx_xpm_file_to_image(vars->mlx, "./textures/floor.xpm", &img_size, &img_size);
}

/*
void	render_cell(t_so_long *memory, t_data *data)
{
	int	i;
	int	j;
	int	color;
	t_data	*img;
	img = memory->img;
	(void)data;

	i = 0;
	j = 0;
	while(i < CELL_SIZE)
	{
		j = 0;
		while (j < CELL_SIZE)
		{
			color = 0x00FF0000;
	//		color = get_color(data, i, j);
			ft_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
}
*/

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
	while (i < memory->map_lines )
	{
		j = 0;
		while (j < memory->map_collumns)
		{
			if (memory->map_as_array[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, imgs->wall, j * CELL_SIZE, i * CELL_SIZE);
			if (memory->map_as_array[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, imgs->floor, j * CELL_SIZE, i * CELL_SIZE);
			if (memory->map_as_array[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, imgs->collect, j * CELL_SIZE, i * CELL_SIZE);
			if (memory->map_as_array[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, imgs->exit, j * CELL_SIZE, i * CELL_SIZE);
			if (memory->map_as_array[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, imgs->player, j * CELL_SIZE, i * CELL_SIZE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

void	display_graphics(t_so_long *memory)
{
//	t_data	*img;
//	t_data	*img2 = NULL;
	t_vars	*vars;
//	char	*relative_path = "./textures/player.xpm";
//	int		img_width = 64;
//	int		img_height = 64;
//	t_imgs	imgs;

//	img = (memory->img);
	vars = (memory->vars);
	load_graphics(memory);
	mlx_loop_hook(vars->mlx, display_map, memory);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, memory);
	mlx_loop(vars->mlx);

//	render_cell(memory, img2);
	/*

	ft_mlx_pixel_put(img, 5, 5, 0x00FF0000);
	ft_mlx_pixel_put(img, 6, 5, 0x00FF0000);
	ft_mlx_pixel_put(img, 7, 5, 0x00FF0000);
	ft_mlx_pixel_put(img, 8, 5, 0x00FF0000);
	ft_mlx_pixel_put(img, 9, 5, 0x00FF0000);
	ft_mlx_pixel_put(img, 1, 5, 0x00FF0000);
	ft_mlx_pixel_put(img, 2, 5, 0x00FF0000);
	ft_mlx_pixel_put(img, 3, 5, 0x00FF0000);
	ft_mlx_pixel_put(img, 4, 5, 0x00FF0000);
	*/
//	img->img = mlx_xpm_file_to_image(vars->mlx, relative_path, &img_width, &img_height);
//	render_cell(memory, img2);

/*
	mlx_put_image_to_window(vars->mlx, vars->win, imgs.wall, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, imgs.player, 64, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, imgs.floor, 128, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, imgs.collect, 192, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, imgs.exit, 256, 0);
*/
//	display_map(memory);
//	memory->map_as_array[0][0] = 'E';
//	memory->map_as_array[0][1] = 'E';
//	mlx_loop_hook(vars->mlx, display_map, memory);
//	mlx_key_hook(vars->win, key_hook, vars);
	//display_map(memory, &imgs);
//	mlx_loop(vars->mlx);

}

int	key_hook(int keycode, t_so_long *memory)
{
	(void)keycode;
	char	**map;
	int		i;
	int		j;

	i = memory->player_i;
	j = memory->player_j;

	map = memory->map_as_array;
//	(void)vars;
//	printf("Hello from key_hook!\n");
//	printf("keycode of button is: %d\n", keycode);
	if (keycode == 53)
	{
		printf("ESC termination\n");
		exit(EXIT_FAILURE);
	}

	if (keycode == 0)
	{
		/*
		if (map[i][j - 1] == 'E')
		{

		}
		*/
		if (map[i][j - 1] != '1')
		{
			map[i][j - 1] = 'P';
			map[i][j] = '0';
			memory->player_j--;
		}
	}

	//write(1, &keycode + '0', 4);
	return (0);
}
