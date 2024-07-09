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


/*int	find_obstacles(char **map, int x, int y)
{
	
}*/


int	col_search(char **multi_map, int x, int y, map_details, int size)
{

}

int	row_search(char **multi_map, int x, int y, map_details, int size)
{


}

t_details	diagonal_search(char **multi_map, int x, int y, map_details)
{
	int	obstacle;
	int	size;
	t_details	big_square_details={};
	
	size = 1;
	obstacle = 0;
	while (obstacle == 0)
	{
		if (multimap[x][y] != map_details.obstacle)
		{
			x++;
			y++;
			if (row_search(multi_map, x, y, size) == 0 && col_search(multi_map, x, y, size) == 0)
			{
				size++;
				continue ;
			}
			else
			{
				obstacle = 1;
			}
		}
	}
	big_square_details.x = x;
	big_square_details.y = y;
	big_square_details.size = (size - 1);
	return (big_square_details);
}

t_details	square_search(char **multi_map, t_details map_details)
{
	int	x;
	int	y;
	t_details	big_square_details={};

	x = -1;
	while (++i < char_to_int(map_details.rows))
	{
		y = -1;
		while (++y < map_details.cols)
		{
			diagonal_search(multi_map, x, y);
			
		}
	}
	return (big_square_details);
}
