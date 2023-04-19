/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:03:11 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/19 14:41:09 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

// t_ray	*new_ray(t_vector orig, t_vector dir)
// {
// 	t_ray	*new_ray;

// 	new_ray = (t_ray *)malloc(sizeof(t_ray));
// 	new_ray->origin = orig;
// 	new_ray->direction = dir;
// 	return (new_ray);
// }


t_ray	*render_ray(int x, int y, t_sky *visual)
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


	//try to print the address of the return of every aux
}

t_vector	ray_at(t_ray ray, double t)
{
	t_vector	result;
	t_vector	aux_vec;

	aux_vec = vec_mul_scalar_apply(ray.direction, t);
	result = add_two_vectors(aux_vec, ray.origin);
	return (result);
}
