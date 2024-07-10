/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senavarr <senavarr@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:33:46 by senavarr          #+#    #+#             */
/*   Updated: 2024/07/10 11:33:50 by senavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

/*Fills the largest free square with the filled symbol, starting in the given coordinates*/
char	**fill_map(char **multi_map, t_lsquare coords, t_details map_details)
{
	int	i;
	int	j;
	int	count;
	int	inn_count;

	printf("El cuadrado mayor empieza en (%d %d) y su tamaño es %d\n", coords.x, coords.y, coords.size);
	count = -1;
	i = coords.x;
	while(++count <= coords.size)
	{
		j = coords.y;
		inn_count = -1;
		while(++inn_count <= coords.size)
		{
			multi_map[i][j] = map_details.fill;
			j++;
		}
		i++;
	}
	print_final_map(multi_map, map_details);
	return (multi_map);
}

/*It prints the final filled map*/
void	print_final_map(char **multi_map, t_details map_details)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map_details.rows)
	{
		y = -1;
		while (++y < map_details.cols)
		{
			write(1, &multi_map[x][y], 1);
		}
		write(1, "\n", 1);
	}
}
