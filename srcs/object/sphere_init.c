/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:21:40 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/18 12:27:38 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

t_sphere2	init_sphere(t_vector center, double radius)
{
	t_sphere2	new;

	new.center = center;
	new.radius = radius;
	return (new);
}

int	ray_hit_sphere(t_sphere2 sphere, t_ray ray)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	oc = subtract_two_vectors(ray.origin, sphere.center);
	a = dot_product_vectors(ray.direction, ray.direction);
	b = dot_product_vectors(oc, ray.direction) * 2.0;
	c = dot_product_vectors(oc, oc) - (sphere.radius * sphere.radius);
	discriminant = (b * b) - (4 * a * c);
	if (discriminant > 0)
		return (1);
	else
		return (0);
}

void	draw_sphere(t_img_data data, t_cam_info info, t_sphere2 sphere)
{
	t_cam		visual;
	t_ray		ray;
	t_vector	color;
	int			i;
	int			j;

	visual = init_cam_struct(info, vec_create(0, 0, 0));
	visual.img = data;
	color = vec_create(1, 1, 0);
	j = data.img_height;
	while (--j >= 0)
	{
		i = -1;
		while (++i < data.img_width)
		{
			ray = render_ray(i, j, visual);
			if (ray_hit_sphere(sphere, ray))
				data.ref[i][j] = get_color_val(color);
		}
	}
}

//Functions to draw coloraccordingly to normalized vector after hitting the sphere

int	ray_hit_sphere2(t_sphere2 sphere, t_ray ray)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	oc = subtract_two_vectors(ray.origin, sphere.center);
	a = dot_product_vectors(ray.direction, ray.direction);
	b = dot_product_vectors(oc, ray.direction) * 2.0;
	c = dot_product_vectors(oc, oc) - (sphere.radius * sphere.radius);
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
		return (-1);
	else
		return ((-b * sqrt(discriminant)) / (2.0 * a));
}

void	draw_sphere2(t_img_data data, t_cam_info info, t_sphere2 sphere)
{
	t_cam		visual;
	t_ray		ray;
	t_vector	color;
	int			i;
	int			j;

	visual = init_cam_struct(info, vec_create(0, 0, 0));
	visual.img = data;
	color = vec_create(1, 1, 0);
	j = data.img_height;
	while (--j >= 0)
	{
		i = -1;
		while (++i < data.img_width)
		{
			ray = render_ray(i, j, visual);
			data.ref[i][j] = atribute_color_to_ray2(ray, sphere);
		}
	}
}
