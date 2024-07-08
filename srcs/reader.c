#include "../includes/bsq.h"

/*Returns the real buffer of the map*/
int	get_buffer(char *filename)
{
	char	temp_buffer[2048];
	int	fo;
	int	bytes;
	int	total_bytes;
	
	bytes = 0;
	total_bytes = 0;
	fo = open(filename, O_RDONLY);
	if (fo == -1)
	{
		close(fo);
		exit(-1);
	}
	
	while((bytes = read(fo, temp_buffer, 2048)) > 0)
	{
		total_bytes += bytes;
	}
	if (bytes == -1)
	{
		close(fo);
		exit(-1);
	}
	printf("El mapa tiene %d carácteres\n", total_bytes);
	return (total_bytes);
}

/*Returns the map as an unidimensional string*/
char	*get_map(char *filename)
{
	int	fo;
	int	reader;
	char	*map;

	map = malloc(get_buffer(filename));
	fo = open(filename, O_RDONLY);
	if (fo == -1)
	{
		close(fo);
		exit(-1);
	}
	reader = read(fo, map, get_buffer(filename));
	if (reader == -1)
	{
		close(fo);
		exit(-1);
	}
	return (map);
}

/*Returns the two first rows, in order to know the symbols and dimensions*/
char *get_two_first_rows(char *map)
{
	int	i;
	int	count;
	char	*rows;

	rows=malloc(2048 * sizeof(char));
	i = -1;
	count = 0;
	while(map[++i] && count < 2)
	{
		rows[i] = map[i];
		if(map[i] == '\n')
			count++;
	}
	rows[i]='\0';
	return (rows);
}

char	*ft_strcat(char *dest, char src)
{
	int	i;
	
	i = 0;
	while(dest[i])
		i++;
	dest[i] = src;
	return (dest);
}

/*Returns a structure with the details of the map*/
t_details	get_map_details(char *map)
{
	char	*first_rows;
	int	i;
	i = 0;
	t_details	map_details={};

	first_rows = get_two_first_rows(map);
	while(first_rows[i] >= '0' && first_rows[i] <='9')
	{
		ft_strcat(map_details.rows, first_rows[i]);
		i++;
	}
	map_details.fill=first_rows[i];
	map_details.obstacle=first_rows[i+1];
	map_details.empty=first_rows[i+2];
	printf("%c\n", map_details.fill);
	return (map_details);
	
}


void	read_map(char *filename)
{
	char	*map;
	map = get_map(filename);
	printf("El mapa:\n%s", map);
	

	/*while(first_rows!='\0')
	{
		
	}
	map_details.fill=buffer[i-1];
	map_details.obstacle=buffer[i-2];
	map_details.empty=buffer[i-3];*/
	
}


//char **get_map_arr(char **map);
