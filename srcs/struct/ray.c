/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:03:11 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/18 15:00:34 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

t_ray	new_ray(t_vector orig, t_vector dir)
{
	t_ray	new_ray;

	new_ray.origin = orig;
	new_ray.direction = dir;
	return (new_ray);
}


t_ray	render_ray(int x, int y, t_cam visual)
{
	t_ray		ray;
	t_vector	aux;
	t_vector	aux2;

	aux = vec_mul_scalar(visual.horizontal,
			(double)(x / (visual.img->img_width - 1)));
	aux2 = vec_mul_scalar(visual.vertical,
			(double)(y / (visual.img->img_height - 1)));
	vec_add_apply(aux, aux2);
	vec_add_apply(aux, visual.lower_left_corner);
	ray = new_ray(visual.origin, vec_sub_apply(aux, visual.origin));
	return (ray);
}

t_vector	ray_at(t_ray ray, double t)
{
	t_vector	result;
	t_vector	aux_vec;

	aux_vec = vec_mul_scalar_apply(ray.direction, t);
	result = add_two_vectors(aux_vec, ray.origin);
	return (result);
}
