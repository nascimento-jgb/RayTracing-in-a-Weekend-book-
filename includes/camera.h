/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:17:43 by helneff           #+#    #+#             */
/*   Updated: 2023/04/26 14:31:40 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec3.h"
# include "ray.h"
# include "state.h"
# include "window.h"
# include "image.h"

typedef int	(*t_ray_trace_func)(const t_state *state, t_ray ray);

typedef struct s_camera
{
	t_image		image;
	t_vec3		orig;
	t_vec3		dir;
	double		width;
	double		height;
	double		aspect_ratio;
	double		focal_length;
	t_vec3		hori;
	t_vec3		vert;
	t_vec3		ll_corner;
}	t_camera;

void	init_camera(t_camera *camera, t_window *window);
t_image	*render(t_camera *camera, const t_state *state);

#endif
