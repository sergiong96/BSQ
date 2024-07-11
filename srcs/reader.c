/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senavarr <senavarr@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:48:43 by senavarr          #+#    #+#             */
/*   Updated: 2024/07/09 18:50:01 by senavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

/*Returns the real buffer of the map*/
int	get_buffer(char *filename)
{
	char	temp_buffer[2048];
	int		fo;
	int		bytes;
	int		total_bytes;

	bytes = 0;
	total_bytes = 0;
	fo = open(filename, O_RDONLY);
	if (fo == -1)
	{
		close(fo);
		exit(-1);
	}
	bytes = read(fo, temp_buffer, 2048);
	while (bytes > 0)
	{
		total_bytes += bytes;
		bytes = read(fo, temp_buffer, 2048);
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
	int		fo;
	int		reader;
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
	int		i;
	int		count;
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

/*Returns a structure with the details of the map*/
t_details	get_map_details(char *map)
{
	t_details	map_details;
	char		*first_rows;
	int			i;

	i = 0;
	map_details.rows = 0;
	map_details.cols = 0;
	map_details.fill = ' ';
	map_details.obstacle = ' ';
	map_details.empty = ' ';
	first_rows = get_two_first_rows(map);
	while (first_rows[i] >= '0' && first_rows[i] <= '9')
	{
		map_details.rows = map_details.rows * 10 + (first_rows[i] - 48);
		i++;
	}
	map_details.empty = first_rows[i];
	map_details.obstacle = first_rows[++i];
	map_details.fill = first_rows[++i];
	while (first_rows[++i] != '\0')
	{
		if (first_rows[i] != '\n')
			map_details.cols++;
	}
	return (map_details);
}

/*Reads the map and returns it as a bidimensional array*/
char	**read_map(char *filename)
{
	char		*map;
	char		**multi_map;
	t_details	map_details;

	map = get_map(filename);
	map_details = get_map_details(map);
	multi_map = create_muti_array(map, map_details);
	return (multi_map);
}
