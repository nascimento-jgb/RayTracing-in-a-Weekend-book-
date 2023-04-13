/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:43:19 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/13 13:02:31 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt_struct.h"

t_ray	new_ray(t_vector orig, t_vector dir)
{
	t_ray	new_ray;

	new_ray.origin.x = orig.x;
	new_ray.origin.y = orig.y;
	new_ray.origin.z = orig.z;
	new_ray.direction.x = dir.x;
	new_ray.direction.y = dir.y;
	new_ray.direction.z = dir.z;
	return (new_ray);
}

t_vector	new_point(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vector	ray_at(t_ray ray, double t)
{
	return (add_two_vectors(ray.origin,
			vector_multiply_scalar(ray.direction, t)));
}

t_vector	ray_color(t_ray ray)
{
	t_vector	unit_direction;
	double		t;

	unit_direction = create_unit_vector(ray.direction);
	t = 0.5 * (unit_direction.y + 1.0);
	return (color_add(color_multiply_scalar(color_new(1.0, 1.0, 1.0), 1.0 - t),
			color_multiply_scalar(color_new(0.5, 0.7, 1.0), t)));
}
