/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senavarr <senavarr@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:33:46 by senavarr          #+#    #+#             */
/*   Updated: 2024/07/11 10:07:10 by vzambran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_lsquare
{
	int	x;
	int	y;
	int	size;
}	t_lsquare;

typedef struct s_details
{
	int		cols;
	int		rows;
	int		diagonal_move;
	char	empty;
	char	obstacle;
	char	fill;
}	t_details;

t_details	get_map_details(char *map);
t_lsquare	square_search(char **map, t_details map_details);
char		**read_map(char *filename);
char		*get_map(char *filename);
char		**fill_map(char **m_map, t_lsquare coords, t_details map_details);
char		**create_muti_array(char *map, t_details map_details);
void		print_final_map(char **multi_map, t_details map_details);

#endif
