/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:36:17 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/07 15:33:27 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/color.h"
#include "../includes/mlx.h"

void	write_color_screen(t_mlx *scene, int x, int y, t_color color)
{
	unsigned int	color_val;
	char			*pixel_ptr;

	color_val = mlx_get_color_value(scene->mlx_ptr, (int)(255.999 * color.r))
		<< 16 | mlx_get_color_value(scene->mlx_ptr, (int)(255.999 * color.g))
		<< 8 | mlx_get_color_value(scene->mlx_ptr, (int)(255.999 * color.b));
	pixel_ptr = scene->img->addr + (y * scene->img->size_l + x
			* (scene->img->bpp / 8));
	*(unsigned int *)pixel_ptr = color_val;
}

t_color	*color_new(double r, double g, double b)
{
	t_color	*new = 0;

	new->r = r;
	new->g = g;
	new->b = b;
	return (new);
}

t_color	*color_multiply_scalar(t_color *color, double num)
{
	color->r *= num;
	color->g *= num;
	color->b *= num;
	return (color);
}

t_color	*color_add(t_color *colorA, t_color *colorB)
{
	t_color	*added = 0;

	added->r = colorA->r + colorB->r;
	added->g = colorA->g + colorB->g;
	added->b = colorA->b + colorB->b;
	return (added);
}
