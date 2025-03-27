/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:13:17 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/27 15:34:47 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define BUFFER_SIZE 1024

char *ft_strjoin(char *s1, char *s2)
{
    char *result;
    size_t i = 0, j = 0;
    size_t len1 = s1 ? strlen(s1) : 0;
    size_t len2 = s2 ? strlen(s2) : 0;

    result = malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);
    while (s1 && i < len1)
    {
        result[i] = s1[i];
        i++;
    }
    while (s2 && j < len2)
    {
        result[i + j] = s2[j];
        j++;
    }
    result[i + j] = '\0';
    return (result);
}


char *read_file(char *filename)
{
    int fd;
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;
    char *content = NULL;
    char *temp;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }
    content = malloc(1);
    if (!content)
        exit(EXIT_FAILURE);
    content[0] = '\0';

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(content, buffer);
        free(content);
        if (!temp)
            exit(EXIT_FAILURE);
        content = temp;
    }
    if (bytes_read < 0)
    {
        perror("Error durante la lectura del archivo");
        free(content);
        close(fd);
        exit(EXIT_FAILURE);
    }
    close(fd);
    return content;
}

/*int main(int argc, char **argv)
{
    char *map_content;

    if (argc != 2)
    {
        write(2, "Uso: ./so_long <archivo.ber>\n", 29);
        return (EXIT_FAILURE);
    }

    map_content = read_file(argv[1]);
    if (map_content)
    {
        printf("Contenido del mapa:\n%s\n", map_content);
        free(map_content);
    }
    return (EXIT_SUCCESS);
}*/