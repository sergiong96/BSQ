
#include "../includes/bsq.h"

/*Returns the map as a bidimensional array*/
char	**create_muti_array(char *map, t_details map_details)
{
	char	**multi_map;
	int		index;
	int		row;
	int		i;

	row = 0;
	i = 0;
	multi_map = malloc(map_details.rows * sizeof(char *));
	index = 0;
	while (map[index] != '\n')
		index++;
	multi_map[row] = malloc((map_details.cols + 1) * sizeof(char));
	while (map[++index] != '\0')
	{
		multi_map[row][i] = map[index];
		i++;
		if (map[index] == '\n')
		{
			multi_map[row][i - 1] = '\0';
			row++;
			multi_map[row] = malloc((map_details.cols + 1) * sizeof(char));
			i = 0;
		}
	}
	return (multi_map);
}
