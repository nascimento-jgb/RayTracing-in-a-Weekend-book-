/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:17:43 by helneff           #+#    #+#             */
/*   Updated: 2023/04/24 19:25:22 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec3.h"
# include "window.h"
# include "image.h"

typedef struct s_camera
{
	t_window	*window;
	t_vec3		pos;
	t_vec3		dir;
	double		width;
	double		height;
	double		aspect_ratio;
	double		focal_length;
}	t_camera;

void	init_camera(t_camera *camera, t_window *window);
void	render(t_image *img, const t_camera *camera);

#endif
