#include "so_long.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
//	printf("Hello from key_hook!\n");
//	printf("keycode of button is: %d\n", keycode);
	if (keycode == 53)
	{
		printf("ESC termination\n");
		exit(EXIT_FAILURE);
	}
	//write(1, &keycode + '0', 4);
	return (0);
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


