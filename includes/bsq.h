#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_lsquare
{
	int x;
	int y;
	int size;
} t_lsquare;

typedef struct s_details
{
	int	cols;
	int 	rows;
	char empty;
	char obstacle;
	char fill;
} t_details;


char**	read_map(char *filename);
t_details	get_map_details(char *map);
t_lsquare	square_search(char **map, t_details map_details);
char	*get_map(char *filename);
char	**fill_map(char **multi_map, t_lsquare coords, t_details map_details);
void	print_final_map(char **multi_map, t_details map_details);

#endif
