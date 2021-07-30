#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "mlx.h"

# define MAP_SIZE_OX 105
# define MAP_SIZE_OY 105
# define MAP_SIZE 1001
# define W_WINDOW 640
# define H_WINDOW 480
# define CELL_SIZE 64

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_imgs
{
	void	*floor;
	void	*wall;
	void	*collect;
	void	*player;
	void	*exit;
}				t_imgs;

typedef struct s_so_long
{
	char	*map_as_line;
	char	**map_as_array;
	int		map_lines;
	int		map_collumns;
	t_vars	*vars;
	t_data	*img;
	t_imgs	*textures;
	int		player_i;
	int		player_j;
	int		collect_count;

}				t_so_long;

int		ft_strlen(char *str);
int		ft_strlen_n(char *str);

t_so_long	*init_memory(void);

void	check_ptr(void *ptr);
void	check_args(int argc, char *argv[]);
int		check_and_open(char *argv[]);

void	check_is_rectangular(char *map);
void	read_and_check_input(int argc, char *argv[], t_so_long *memory);
void	check_is_closed(char *map);
void	check_map_contents(char *map);

void	convert_map_line_to_array(t_so_long *memory);
void	count_lines_and_collumns(t_so_long *memory);
void	find_player_position(t_so_long *memory);
void	count_collectibles(t_so_long *memory);

void	graphics_experience(void);
void	init_graphics(t_so_long *memory);
void	display_graphics(t_so_long *memory);
int		key_hook(int keycode, t_so_long *memory);

#endif
