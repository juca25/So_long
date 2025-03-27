/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:49:17 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/27 15:57:14 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *filename)
{
	int	len;
	if(len < 4)
		return (0);
	if(strcmp(&filename[len - 4], ".ber") != 0)
		return (0);
	return (1);
}

int	check_rectangular(char **map, int line_count)
{
	int	len;
	int i;

	len = strlen(map[0]);
	i = 1;
	while (i < line_count)
	{
		if (strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_valid_chars(char **map, int line_count)
{
	int i;
	int j;
	
	i = 0;
	while (i < line_count)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' &&
				map[i][j] != 'P' && map[i][j] != 'E' &&
				map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_elements	count_elements(char **map, int line_count)
{
	t_elements elems;
	int i;
	int j;

	elems = (t_elements){0, 0, 0};
	i = 0;
	while (i < line_count)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				elems.count_p++;
			else if (map[i][j] == 'E')
				elems.count_e++;
			else if (map[i][j] == 'C')
				elems.count_c++;
			j++;
		}
		i++;
	}
	return (elems);
}

int check_walls(char **map, int line_count)
{
	int	len;
	int i;
	int j;

	len = strlen(map[0]);
	j = 0;
	i = 0;
	while(j < len)
	{
		if (map[0][j] != '1' || map[line_count - 1][j] != '1')
			return (0);
		j++;
	}
	while(i < line_count)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}