#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

# define MAP_SIZE_OX 105
# define MAP_SIZE_OY 105
# define MAP_SIZE 1001

int		ft_strlen(char *str);
int		ft_strlen_n(char *str);

void	check_ptr(void *ptr);
void	check_args(int argc, char *argv[]);
int		check_and_open(char *argv[]);

void	check_is_rectangular(char *map);
void	check_input(int argc, char *argv[]);
void	check_is_closed(char *map);
void	check_map_contents(char *map);


#endif
