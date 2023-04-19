/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:36:17 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/19 10:43:23 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_struct.h"
#include "minirt_mlx.h"

int	get_color_val(t_vector color)
{
	int		x;
	int		y;
	int		z;

	x = blend(color.x, 0.0, 0.999) * 256.0;
	y = blend(color.y, 0.0, 0.999) * 256.0;
	z = blend(color.z, 0.0, 0.999) * 256.0;
	return (x << 16 | y << 8 | z);
}

int	get_color_sample_gamma(t_vector color)
{
	double	scale;
	double	x;
	double	y;
	double	z;

	scale = 1.0 / 50;
	x = sqrt(color.x * scale);
	y = sqrt(color.y * scale);
	z = sqrt(color.z * scale);
	x = blend(x, 0.0, 0.999) * 256.0;
	y = blend(y, 0.0, 0.999) * 256.0;
	z = blend(z, 0.0, 0.999) * 256.0;
	return ((int)x << 16 | (int)y << 8 | (int)z);
}

t_vector	get_color(int rgb)
{
	t_vector	result;

	result.x = (rgb & (0xFF << 16)) >> 16;
	result.y = (rgb & (0xFF << 8)) >> 8;
	result.z = rgb & 0xFF;
	return (result);
}
