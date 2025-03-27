/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:35:11 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/27 15:56:21 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include </home/juan-ser/so_long/minilibx-linux/mlx.h>

typedef struct s_elements {
    int count_p;
    int count_e;
    int count_c;
} t_elements;

char *read_file(char *filename);
int	check_extension(char *filename);
int	check_rectangular(char **map, int line_count);
int	check_valid_chars(char **map, int line_count);
t_elements	count_elements(char **map, int line_count);
int check_walls(char **map, int line_count);