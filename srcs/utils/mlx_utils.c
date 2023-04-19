/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:13:49 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/19 07:56:42 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

int	exit_program(void)
{
	exit(0);
	return (0);
}

int	mlx_key_handle(int keycode)
{
	if (keycode == 53)
		return (exit_program());
	return (0);
}

void	mlx_draw_by_img_data(t_mlx_data *prog, t_img_data *data)
{
	int		width;
	int		height;
	int		next;
	char	*dest;

	width = -1;
	while ((++width) < data->img_width)
	{
		height = -1;
		while ((++height) < data->img_height)
		{
			next = (data->img_height - height - 1)
				* prog->size_l;
			next += width * (prog->bpp / 8);
			dest = prog->addr + next;
			*(unsigned int *)dest = data->ref[width][height];
		}
	}
}

int	mlx_exec(t_img_data *image, char *name)
{
	t_mlx_ptrs	init;
	t_mlx_data	*new;

	init.mlx_ptr = mlx_init();
	init.win_ptr = mlx_new_window(init.mlx_ptr, image->img_width,
			image->img_height, name);
	new = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	new->img_ptr = mlx_new_image(init.mlx_ptr, image->img_width,
			image->img_height);
	new->addr = mlx_get_data_addr(new->img_ptr, &(new->bpp),
			&(new->size_l), &(new->endian));
	mlx_draw_by_img_data(new, image);
	mlx_put_image_to_window(init.mlx_ptr, init.win_ptr, new->img_ptr, 0, 0);
	mlx_destroy_image(init.mlx_ptr, new->img_ptr);
	mlx_hook(init.win_ptr, 2, 1L << 0, mlx_key_handle, 0);
	mlx_hook(init.win_ptr, 17, 1L << 17, exit_program, 0);
	mlx_loop(init.mlx_ptr);
	free(new);
	return (0);
}
