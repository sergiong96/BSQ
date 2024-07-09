#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_bsq
{
	int x;
	int y;
	int size;
} t_bsq;

typedef struct s_details
{
	int	cols;
	char *rows;
	char *empty;
	char *obstacle;
	char *fill;
} t_details;


void	read_map(char *filename);



#endif
