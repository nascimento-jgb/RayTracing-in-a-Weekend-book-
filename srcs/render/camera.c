/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:51:58 by helneff           #+#    #+#             */
/*   Updated: 2023/04/25 15:58:17 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "camera.h"
#include "color.h"
#include "vec3.h"

void	init_camera(t_camera *camera, t_window *window)
{
	camera->window = window;
	camera->pos = (t_vec3){0.0, 0.0, 0.0};
	camera->dir = (t_vec3){0.0, 0.0, 0.0};
	camera->aspect_ratio = (double)window->height / window->width;
	camera->focal_length = 1;
	camera->height = 2;
	camera->width = camera->height * camera->aspect_ratio;
}

void	render(t_image *img, const t_state *state)
{
	const int	color = int2col(state, 0x00ABCDEF);

	if (init_image(img, state->window) == -1)
		return ;
	fill_color(img, color);
}
