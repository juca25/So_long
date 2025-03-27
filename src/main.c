/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:36:58 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/27 15:59:26 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    void *mlx_ptr;
    void *win_ptr;

    // Inicializa la conexión con el servidor gráfico
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
    {
        write(2, "Error al inicializar MiniLibX\n", 31);
        exit(EXIT_FAILURE);
    }

    // Crea una nueva ventana de 800x600 píxeles con el título "so_long"
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "so_long");
    if (!win_ptr)
    {
        write(2, "Error al crear la ventana\n", 26);
        exit(EXIT_FAILURE);
    }

    // Entra en el ciclo de eventos de MiniLibX
    mlx_loop(mlx_ptr);

    return (0);
}
