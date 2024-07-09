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
char	*get_two_first_rows(char *map)
{
	int	i;
	int	count;
	char	*rows;

	rows = malloc(2048 * sizeof(char));
	i = -1;
	count = 0;
	while (map[++i] && count < 2)
	{
		rows[i] = map[i];
		if (map[i] == '\n')
			count++;
	}
	rows[i] = '\0';
	return (rows);
}

/*Concat a char to a string*/
char	*ft_append(char *dest, char src)
{
	int	i;
	
	i = 0;
	while(dest[i]!='\0')
		i++;
	dest[i] = src;
	dest[++i] = '\0';
	return (dest);
}

int	char_to_int(char *number)
{
	int	num;
	int	i;
	
	num = 0;
	i = 0;
	while (number[i] >= '0' && number[i] <= '9')
	{
		num = num * 10 + (number[i] - 48);
		i++;
	}
	return (num);
}


/*Returns a structure with the details of the map*/
t_details	get_map_details(char *map)
{
	char	*first_rows;
	int	i;
	t_details	map_details;
	
	i = 0;
	map_details.rows = malloc(50);
	map_details.cols = 0;
	map_details.fill = malloc(2);
	map_details.obstacle = malloc(2);
	map_details.empty = malloc(2);
	first_rows = get_two_first_rows(map);
	while(first_rows[i] >= '0' && first_rows[i] <='9')
	{
		ft_append(map_details.rows, first_rows[i]);
		i++;
	}
	ft_append(map_details.empty, first_rows[i]);
	ft_append(map_details.obstacle, first_rows[++i]);
	ft_append(map_details.fill, first_rows[++i]);
	while(first_rows[++i] != '\0')
	{
		if(first_rows[i] != '\n')
			map_details.cols++;
	}
	return (map_details);
}

char	**create_muti_array(char *map, t_details map_details)
{
	int	index;
	char	**multi_map;
	int	row;
	int	i;

	row = 0;
	i=-1;
	multi_map = malloc(char_to_int(map_details.rows));
	index = -1;
	while(map[index]!='\n')
	{
		index++;
	}
	multi_map[row]=malloc(map_details.cols);
	while (map[++index] != '\0')
	{
		multi_map[row][++i] = map[index];
		if(map[index] == '\n')
		{
			row++;
			multi_map[row]=malloc(map_details.cols);
			i=-1;
		}
	}
	
	return (multi_map);
}
void	read_map(char *filename)
{
	char	*map;
	char	**multi_map;

	t_details	map_details;
	map = get_map(filename);
	map_details = get_map_details(map);
	multi_map=create_muti_array(map, map_details);
	


}



