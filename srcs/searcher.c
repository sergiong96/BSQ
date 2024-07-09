/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senavarr <senavarr@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:59:24 by senavarr          #+#    #+#             */
/*   Updated: 2024/07/09 18:59:31 by senavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

/*Checks if there are obstacles in previous cols, returning 1 if it finds one*/
int	col_checker(char **multi_map, int x, int y, int diagonal_move, t_details map_details)
{
	int	count;

	count = -1;
	if (multi_map[x][y] == map_details.obstacle)
		return (1);
	while (++count < diagonal_move)
	{
		//printf("Col va a comprobar (%d, %d). Tamaño: %d\n", x, y, size);
		if (multi_map[x][--y] == map_details.obstacle)
		{
			//printf("Obstáculo en (%d, %d). Tamaño: %d\n\n", x, y, diagonal_move);
			return (1);
		}
	}
	return (0);
}

/*Checks if there are obstacles in previous rows, returning 1 if it finds one*/
int	row_checker(char **multi_map, int x, int y, int diagonal_move, t_details map_details)
{
	int	count;

	count = -1;
	if (multi_map[x][y] == map_details.obstacle)
		return (1);
	while (++count < diagonal_move)
	{
		//printf("Row va a comprobar (%d, %d). Tamaño: %d\n", x, y, size);
		if (multi_map[--x][y] == map_details.obstacle)
		{
			//printf("Obstáculo en (%d, %d). Tamaño: %d\n\n", x, y, diagonal_move);
			return (1);
		}
	}
	return (0);
}

/*Search for free squares along the diagonal*/
t_lsquare	diagonal_search(char **multi_map, int x, int y, t_details map_details)
{
	t_lsquare	coords;
	int		diagonal_move;

	coords.size = 0;
	diagonal_move = 0;
	while (x < (char_to_int(map_details.rows)) && y < (map_details.cols) && multi_map[x][y] != map_details.obstacle)
	{
		x++;
		y++;
		diagonal_move++;
		if (row_checker(multi_map, x, y, diagonal_move, map_details) == 1 
		|| col_checker(multi_map, x, y, diagonal_move, map_details) == 1)
		{
			diagonal_move--;
			x--;
			y--;
			break ;
		}
	}
	if (diagonal_move > 0)
	{
		coords.x = x - diagonal_move;
		coords.y = y - diagonal_move;
		coords.size = diagonal_move;
	}	
	return (coords);
}

/*Returns the struct with the details about the coordinates and size where the largest square starts*/
t_lsquare	square_search(char **multi_map, t_details map_details)
{
	int	x;
	int	y;
	t_lsquare	t_largest_square;
	t_lsquare	temp_largest_square;

	t_largest_square.size = 0;
	temp_largest_square.size = 0;
	x = -1;
	while (++x < char_to_int(map_details.rows) - 1)
	{
		y = -1;
		while (++y < map_details.cols - 1)
		{
			temp_largest_square = diagonal_search(multi_map, x, y, map_details);
			if(temp_largest_square.size>0)
			{
				printf("Cuadrado libre en %d %d. Tamaño: %d\n",temp_largest_square.x,temp_largest_square.y, temp_largest_square.size);
			}
			if (temp_largest_square.size > t_largest_square.size)
				t_largest_square = temp_largest_square;
		}
	}
	return (t_largest_square);
}
