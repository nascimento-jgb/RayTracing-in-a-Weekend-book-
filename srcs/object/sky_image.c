/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:43:41 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/19 10:44:43 by jonascim         ###   ########.fr       */
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
	vec_add_apply(aux, aux2);
	return (get_color_val(aux));
}

// int	atribute_color_to_ray2(t_ray ray, t_sphere2 sphere)
// {
// 	t_vector	aux;
// 	t_vector	aux2;
// 	t_vector	normal;
// 	double		t;
// 	int			new;

// 	t = ray_hit_sphere2(sphere, ray);
// 	if (t > 0.0)
// 	{
// 		normal = subtract_two_vectors(ray_at(ray, t), sphere.center);
// 		vec_div_scalar_apply(normal, sphere.radius);
// 		new = get_color_val(normal);
// 		return (new);
// 	}
// 	aux = create_unit_vector(ray.direction);
// 	t = 0.5 * (aux.y + 1.0);

// 	aux = vec_mul_scalar_apply(vec_create(1, 1, 1), 1.0 - t);
// 	aux2 = vec_mul_scalar_apply(vec_create(0.5, 0.7, 1), t);
// 	vec_add_apply(aux, aux2);
// 	new = get_color_val(aux);
// 	return (new);
// }

t_sky_info	*init_sky_info(double w, double h, double fl)
{
	t_sky_info	*new;

	new = (t_sky_info *)malloc(sizeof(t_sky_info));
	if (!new)
		return (NULL);
	new->viewport_width = w;
	new->viewport_height = h;
	new->focal_lenght = fl;
	return (new);
}

t_sky	*init_sky_struct(t_img_data *data, t_sky_info *info)
{
	t_sky		*res;
	t_vector	aux;
	t_vector	aux2;
	t_vector	aux3;

	res = ft_calloc(1, sizeof(t_sky));
	res->data = data;
	res->origin = (t_vector){0, 0, 0};
	res->horizontal = (t_vector){info->viewport_width, 0, 0};
	res->vertical = (t_vector){0, info->viewport_height, 0};
	vec_div_scalar_apply(res->horizontal, 2.0);
	vec_div_scalar_apply(res->vertical, 2.0);
	aux = add_two_vectors(res->horizontal, res->vertical);
	aux2 = (t_vector){0, 0, info->focal_lenght};
	aux3 = add_two_vectors(aux, aux2);
	res->lower_left_corner = subtract_two_vectors((t_vector){0, 0, 0}, aux3);
	vec_mul_scalar_apply(res->horizontal, 2.0);
	vec_mul_scalar_apply(res->vertical, 2.0);
	return (res);
}

void	create_sky_image(t_img_data *data, t_sky_info *info)
{
	t_sky	*new_sky;
	t_ray	*ray;
	int		i;
	int		j;

	new_sky = init_sky_struct(data, info);
	j = data->img_height;
	while (--j >= 0)
	{
		i = -1;
		while (++i < data->img_width)
		{
			ray = render_ray(i, j, new_sky);
			data->ref[i][j] = atribute_color_to_ray(ray);
		}
	}
}
