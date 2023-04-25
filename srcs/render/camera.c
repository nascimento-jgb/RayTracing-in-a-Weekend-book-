/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:51:58 by helneff           #+#    #+#             */
/*   Updated: 2023/04/25 16:40:58 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <mlx.h>

#include "camera.h"
#include "parser.h"
#include "color.h"

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

t_image	*render(t_camera *camera, const t_state *state)
{
	const int	background = int2col(state, 0x00ABCDEF);

	if (init_image(&camera->image, state->window) == -1)
		return (NULL);
	fill_color(&camera->image, background);
	return (&camera->image);
}
