/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senavarr <senavarr@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:48:17 by senavarr          #+#    #+#             */
/*   Updated: 2024/07/09 18:48:37 by senavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	main(int argc, char *argv[])
{
	char	*single_map;
	char	**multi_map;
	t_details	map_details;
	t_lsquare	coords;
	
	argv++;
	while(*argv != NULL)
	{
		single_map = get_map(*argv);
		map_details = get_map_details(single_map);
		multi_map = read_map(*argv);
		coords = square_search(multi_map, map_details);
		fill_map(multi_map, coords, map_details);
		argv++;
		if (argc > 2)
			write(1, "\n", 1);
	}
	return (0);
}
