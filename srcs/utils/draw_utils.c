/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:16:16 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/18 15:23:41 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

void	draw_image(t_img_data *data)
{
	t_vector	color;
	double		x;
	double		y;
	int			rgb;

	y = -1;
	while ((++y) < data->img_height)
	{
		x = -1;
		while ((++x) < data->img_width)
		{
			color = vec_create(x / data->img_width, y / data->img_height, 0.25);
			rgb = get_color_val(color);
			data->ref[(int)x][(int)y] = rgb;
		}
	}
}

void	draw_vertical_line(t_img_data data, int x)
{
	t_vector	color;
	int			rgb;
	int			y;

	y = -1;
	while ((++y) < data.img_height)
	{
		color = vec_create(1, 1, 1);
		rgb = get_color_val(color);
		data.ref[x][y] = rgb;
	}
}

void	draw_horizontal_line(t_img_data data, int y)
{
	t_vector	color;
	int			rgb;
	int			x;

	x = -1;
	while ((++x) < data.img_height)
	{
		color = vec_create(1, 1, 1);
		rgb = get_color_val(color);
		data.ref[x][y] = rgb;
	}
}
