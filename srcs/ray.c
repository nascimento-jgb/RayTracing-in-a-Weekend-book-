/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:43:19 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/07 15:36:05 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"
#include "../includes/color.h"
#include "../includes/vector.h"

t_ray	*new_ray(t_point *orig, t_vector *dir)
{
	t_ray	*new_ray = 0;

	new_ray->origin->x = orig->x;
	new_ray->origin->y = orig->y;
	new_ray->origin->z = orig->z;
	new_ray->direction->i = dir->i;
	new_ray->direction->j = dir->j;
	new_ray->direction->k = dir->k;
	return (new_ray);
}

t_point	*new_point(double x, double y, double z)
{
	t_point	*new = 0;

	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}

t_vector	*ray_at(t_ray *ray, double t)
{
	return (add_two_vectors((t_vector *)ray->origin, vector_times_scalar(ray->direction, t)));
}

t_color	*ray_color(const t_ray *ray)
{
	t_vector	*unit_direction;
	double		t;

	unit_direction = create_unit_vector(ray->direction);
	t = 0.5 * (unit_direction->j + 1.0);
	return (color_add(color_multiply_scalar(color_new(1.0, 1.0, 1.0), 1.0 - t),
			color_multiply_scalar(color_new(0.5, 0.7, 1.0), t)));
}
