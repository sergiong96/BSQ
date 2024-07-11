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

/*Checks if there are obstacles in the current or previous columns, 
returning 1 if it finds one*/
int	col_c(char **multi_map, int x, int y, t_details map_details)
{
	int	count;

	count = -1;
	if (multi_map[x][y] == map_details.obstacle)
		return (1);
	while (++count < map_details.diagonal_move)
	{
		if (multi_map[x][--y] == map_details.obstacle)
		{
			return (1);
		}
	}
	return (0);
}

/*Checks if there are obstacles in the current or previous rows, 
returning 1 if it finds one*/
int	row_c(char **multi_map, int x, int y, t_details map_details)
{
	int	count;

	count = -1;
	if (multi_map[x][y] == map_details.obstacle)
		return (1);
	while (++count < map_details.diagonal_move)
	{
		if (multi_map[--x][y] == map_details.obstacle)
		{
			return (1);
		}
	}
	return (0);
}

/*Search for free squares along the diagonal*/
t_lsquare	diagonal_s(char **m_map, int x, int y, t_details m_det)
{
	t_lsquare	coords;

	coords.size = 0;
	m_det.diagonal_move = 0;
	while (x < m_det.rows - 1
		&& y < m_det.cols - 1 && m_map[x][y] != m_det.obstacle)
	{
		x++;
		y++;
		m_det.diagonal_move++;
		if (row_c(m_map, x, y, m_det) == 1 || col_c(m_map, x, y, m_det) == 1)
		{
			m_det.diagonal_move--;
			x--;
			y--;
			break ;
		}
	}
	if (m_det.diagonal_move > 0)
	{
		coords.x = x - m_det.diagonal_move;
		coords.y = y - m_det.diagonal_move;
		coords.size = m_det.diagonal_move;
	}
	return (coords);
}

/*Returns the details about the coordinates and size 
where the largest square starts*/
t_lsquare	square_search(char **multi_map, t_details map_details)
{
	t_lsquare	t_largest_square;
	t_lsquare	temp_largest_square;
	int			x;
	int			y;

	t_largest_square.size = 0;
	temp_largest_square.size = 0;
	x = -1;
	while (++x < (map_details.rows) - 1)
	{
		y = -1;
		while (++y < map_details.cols - 1)
		{
			temp_largest_square = diagonal_s(multi_map, x, y, map_details);
			if (temp_largest_square.size > t_largest_square.size)
				t_largest_square = temp_largest_square;
		}
	}
	return (t_largest_square);
}
