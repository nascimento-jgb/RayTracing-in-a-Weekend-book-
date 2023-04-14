/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:16:16 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/14 10:55:32 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt_mlx.h"

void	draw_image(t_img_data *data)
{
	t_vector	*color;
	double		i;
	double		j;
	int			rgb;

	i = -1;
	while ((++i) < data->img_height)
	{
		j = -1;
		while ((++j) < data->img_width)
		{
			color = vec_create(i / data->img_width, j / data->img_height,
					1.0 / 4.0);
			rgb = get_color_val(color);
			data->ref[(int)i][(int)j] = rgb;
			free(color);
		}
	}
}

void	draw_vertical_line(t_img_data *data, int x)
{
	t_vector	*color;
	int			rgb;
	int			y;

	y = -1;
	while ((++y) < data->img_height)
	{
		color = vec_create(1, 1, 1);
		rgb = get_color_val(color);
		data->ref[x][y] = rgb;
		free(color);
	}
}

void	draw_horizontal_line(t_img_data *data, int y)
{
	t_vector	*color;
	int			rgb;
	int			x;

	x = -1;
	while ((++x) < data->img_height)
	{
		color = vec_create(1, 1, 1);
		rgb = get_color_val(color);
		data->ref[x][y] = rgb;
		free(color);
	}
}
