/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:36:17 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/13 13:11:03 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt_struct.h"
#include "../../includes/minirt_mlx.h"

void	write_color_screen(t_mlx *scene, int x, int y, t_vector color)
{
	unsigned int	color_val;
	char			*pixel_ptr;

	color_val = mlx_get_color_value(scene->mlx_ptr, (int)(255.999 * color.x))
		<< 16 | mlx_get_color_value(scene->mlx_ptr, (int)(255.999 * color.y))
		<< 8 | mlx_get_color_value(scene->mlx_ptr, (int)(255.999 * color.z));
	pixel_ptr = scene->img_data.addr + (y * scene->img_data.size_l + x
			* (scene->img_data.bpp / 8));
	*(unsigned int *)pixel_ptr = color_val;
}

t_vector	color_new(double r, double g, double b)
{
	t_vector	new;

	new.x = r;
	new.y = g;
	new.z = b;
	return (new);
}

t_vector	color_multiply_scalar(t_vector color, double num)
{
	color.x *= num;
	color.y *= num;
	color.z *= num;
	return (color);
}

t_vector	color_add(t_vector colorA, t_vector colorB)
{
	t_vector	added;

	added.x = colorA.x + colorB.x;
	added.y = colorA.y + colorB.y;
	added.z = colorA.z + colorB.z;
	return (added);
}
