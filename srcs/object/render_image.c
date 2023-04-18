/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:43:41 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/18 12:27:38 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

int	atribute_color_to_ray(t_ray ray)
{
	t_vector	aux;
	t_vector	aux2;
	double		t;
	int			new;

	aux = create_unit_vector(ray.direction);
	t = 0.5 * (aux.y + 1.0);
	aux = vec_mul_scalar_apply(vec_create(1, 1, 1), 1.0 - t);
	aux2 = vec_mul_scalar_apply(vec_create(0.5, 0.7, 1), t);
	vec_add_apply(aux, aux2);
	new = get_color_val(aux);
	return (new);
}

int	atribute_color_to_ray2(t_ray ray, t_sphere2 sphere)
{
	t_vector	aux;
	t_vector	aux2;
	t_vector	normal;
	double		t;
	int			new;

	t = ray_hit_sphere2(sphere, ray);
	if (t > 0.0)
	{
		normal = subtract_two_vectors(ray_at(ray, t), sphere.center);
		vec_div_scalar_apply(normal, sphere.radius);
		new = get_color_val(normal);
		return (new);
	}
	aux = create_unit_vector(ray.direction);
	t = 0.5 * (aux.y + 1.0);

	aux = vec_mul_scalar_apply(vec_create(1, 1, 1), 1.0 - t);
	aux2 = vec_mul_scalar_apply(vec_create(0.5, 0.7, 1), t);
	vec_add_apply(aux, aux2);
	new = get_color_val(aux);
	return (new);
}

t_cam_info	init_cam_info(double w, double h, double fl)
{
	t_cam_info	new;

	new.viewport_width = w;
	new.viewport_height = h;
	new.focal_lenght = fl;
	return (new);
}

t_cam	init_cam_struct(t_cam_info info, t_vector origin)
{
	t_cam		new;
	t_vector	aux;
	t_vector	aux2;
	t_vector	aux3;

	new.img = *(t_img_data *)malloc(sizeof(t_img_data));
	new.origin = origin;
	new.horizontal = vec_create(info.viewport_width, 0, 0);
	new.vertical = vec_create(0, info.viewport_height, 0);
	vec_div_scalar_apply(new.horizontal, 2.0);
	vec_div_scalar_apply(new.vertical, 2.0);
	aux = add_two_vectors(new.horizontal, new.vertical);
	aux2 = vec_create(0, 0, info.focal_lenght);
	aux3 = add_two_vectors(aux, aux2);
	new.lower_left_corner = subtract_two_vectors(origin, aux3);
	vec_mul_scalar_apply(new.horizontal, 2.0);
	vec_mul_scalar_apply(new.vertical, 2.0);
	return (new);
}

void	create_render_image(t_img_data data, t_cam_info info)
{
	t_cam	visual;
	t_ray	ray;
	int		i;
	int		j;

	visual = init_cam_struct(info, vec_create(0, 0, 0));
	visual.img = data;
	j = data.img_height;
	while (--j >= 0)
	{
		i = -1;
		while (++i < data.img_width)
		{
			ray = render_ray(i, j, visual);
			data.ref[i][j] = atribute_color_to_ray(ray);
		}
	}
}
