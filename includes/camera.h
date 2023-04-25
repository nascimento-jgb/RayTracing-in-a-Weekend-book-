/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:17:43 by helneff           #+#    #+#             */
/*   Updated: 2023/04/25 16:48:41 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec3.h"
# include "state.h"
# include "window.h"
# include "image.h"

typedef struct s_camera
{
	t_image		image;
	t_vec3		pos;
	t_vec3		dir;
	double		width;
	double		height;
	double		aspect_ratio;
	double		focal_length;
}	t_camera;

void	init_camera(t_camera *camera, t_window *window);
t_image	*render(t_camera *camera, const t_state *state);

#endif
