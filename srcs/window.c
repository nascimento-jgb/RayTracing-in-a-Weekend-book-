/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:17:40 by helneff           #+#    #+#             */
/*   Updated: 2023/04/24 16:56:44 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <mlx.h>
#include <libft.h>

#include "window.h"

static int	exit_program(void)
{
	exit(0);
	return (0);
}

static int	mlx_key_handle(int keycode)
{
	if (keycode == 53)
		return (exit_program());
	return (0);
}

int	init_mlx_window(t_window *window, char *name, int width, int height)
{
	window->mlx_ptr = mlx_init();
	if (!window->mlx_ptr)
		return (-1);
	window->win_ptr = mlx_new_window(window->mlx_ptr, width, height, name);
	if (!window->win_ptr)
		return (-1);
	mlx_hook(window->win_ptr, 2, 1L << 0, mlx_key_handle, 0);
	mlx_hook(window->win_ptr, 17, 1L << 17, exit_program, 0);
	return (0);
}
