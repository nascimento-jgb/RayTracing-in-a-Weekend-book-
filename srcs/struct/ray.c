/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:03:11 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/22 12:23:27 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

int	atribute_color_to_ray(t_ray *ray)
{
	t_vector	aux;
	t_vector	aux2;
	double		t;

	aux = create_unit_vector(ray->direction);
	t = 0.5 * (aux.y + 1.0);
	aux = vec_mul_scalar_apply((t_vector){1, 1, 1}, 1.0 - t);
	aux2 = vec_mul_scalar_apply((t_vector){0.5, 0.7, 1}, t);
	aux = vec_add_apply(aux, aux2);
	return (get_color_val(aux));
}

int	atribute_color_to_ray2(t_sphere2 *sphere, t_ray *ray)
{
	t_vector	aux;
	t_vector	aux2;
	t_vector	normal;
	t_vector	unit;
	double		t;

	t = ray_hit_sphere2(sphere, ray);
	if (t > 0)
	{
		normal = subtract_two_vectors(ray_at(ray, t), sphere->center);
		unit = create_unit_vector(normal);
		unit = vec_add_apply(unit, (t_vector){1, 1, 1});
		unit = vec_mul_scalar_apply(unit, 0.5);
		return (get_color_val(unit));
	}
	aux = create_unit_vector(ray->direction);
	t = 0.5 * (aux.y + 1.0);
	aux = vec_mul_scalar_apply((t_vector){1, 1, 1}, 1.0 - t);
	aux2 = vec_mul_scalar_apply((t_vector){0.5, 0.7, 1}, t);
	aux = vec_add_apply(aux, aux2);
	return (get_color_val(aux));
}

t_ray	*render_ray(int x, int y, t_cam *visual)
{
	t_ray		*res;
	t_vector	aux;
	t_vector	aux2;

	res = ft_calloc(1, sizeof(t_ray));
	aux = vec_mul_scalar(visual->horizontal,
			(double)x / (visual->data->img_width - 1));
	aux2 = vec_mul_scalar(visual->vertical,
			(double)y / (visual->data->img_height - 1));
	aux = vec_add_apply(aux, aux2);
	aux = vec_add_apply(aux, visual->lower_left_corner);
	aux = vec_sub_apply(aux, visual->origin);
	res->origin = visual->origin;
	res->direction = aux;
	return (res);
}

t_vector	ray_at(t_ray *ray, double t)
{
	t_vector	result;

	result = vec_mul_scalar(ray->direction, t);
	result = vec_add_apply(result, ray->origin);
	return (result);
}
