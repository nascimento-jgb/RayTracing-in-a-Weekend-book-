/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:03:11 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/14 11:14:56 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt_struct.h"

t_ray	*new_ray(t_vector *orig, t_vector *dir)
{
	t_ray	*new_ray;

	new_ray = (t_ray *)malloc(sizeof(t_ray));
	if (!new_ray)
		return (NULL);
	new_ray->origin->x = orig->x;
	new_ray->origin->y = orig->y;
	new_ray->origin->z = orig->z;
	new_ray->direction->x = dir->x;
	new_ray->direction->y = dir->y;
	new_ray->direction->z = dir->z;
	return (new_ray);
}

t_vector	*new_point(double x, double y, double z)
{
	t_vector	*new_pt;

	new_pt = (t_vector *)malloc(sizeof(t_vector));
	if (!new_pt)
		return (NULL);
	new_pt->x = x;
	new_pt->y = y;
	new_pt->z = z;
	return (new_pt);
}

t_vector	*ray_at(t_ray *ray, double t)
{
	return (add_two_vectors(ray->origin,
			vector_multiply_scalar(ray->direction, t)));
}

// t_vector	ray_color(t_ray *ray)
// {
// 	t_vector	*unit_direction;
// 	double		t;

// 	unit_direction = (t_vector *)malloc(sizeof(t_vector));
// 	if (!unit_direction)
// 		return (NULL);
// 	unit_direction = create_unit_vector(ray->direction);
// 	t = 0->5 * (unit_direction->y + 1->0);
// 	return (color_add(color_multiply_scalar(color_new(1->0, 1->0, 1->0), 1->0 - t),
// 			color_multiply_scalar(color_new(0->5, 0->7, 1->0), t)));
// }
