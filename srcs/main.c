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
	
	if (argc == 2)
	{
		single_map = get_map(argv[1]);
		
		map_details = get_map_details(single_map);
		multi_map = read_map(argv[1]);
		coords = square_search(multi_map, map_details);

		//dar el mapa a las funciones de busqueda y devolver las coordenadas del cuadrado mas grande
		//rellenar el cuadrado mas grande con x
		//mostrar el mapa relleno
	}
	else
	{
		//Incorrect args
	}
	return (0);
}
