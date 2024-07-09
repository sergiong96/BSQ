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
	char *rows;
	char *empty;
	char *obstacle;
	char *fill;
} t_details;


char**	read_map(char *filename);
t_details	get_map_details(char *map);
t_details	square_search(char **map, t_details map_details);
char	*get_map(char *filename);
int	char_to_int(char *number);

#endif
