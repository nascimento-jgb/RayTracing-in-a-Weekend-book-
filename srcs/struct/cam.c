/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:43:41 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 10:08:53 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

t_ray	*camera_get_ray(t_cam *cam, double u, double v)
{
	t_ray		*res;
	t_vector	aux;
	t_vector	aux2;
	t_vector	aux3;

	res = (t_ray *)malloc(sizeof(t_ray));
	if (!res)
		return (NULL);
	aux2 = vec_mul_scalar(cam->horizontal, u);
	aux = add_two_vectors(cam->lower_left_corner, aux2);
	aux3 = vec_mul_scalar(cam->vertical, v);
	aux = vec_add_apply(aux, aux3);
	aux = vec_sub_apply(aux, cam->origin);
	res->origin = cam->origin;
	res->direction = aux;
	return (res);
}

void	create_sky_image(t_img_data *data, t_cam_info *info)
{
	t_cam	*new_sky;
	t_ray	*ray;
	int		i;
	int		j;

	new_sky = init_cam_struct(data, info);
	j = data->img_height;
	while (--j >= 0)
	{
		i = -1;
		while (++i < data->img_width)
		{
			ray = render_ray(i, j, new_sky);
			data->ref[i][j] = atribute_color_to_ray(ray);
			free(ray);
		}
	}
	free(new_sky);
}

t_cam	*init_cam_struct(t_img_data *data, t_cam_info *info)
{
	t_cam		*res;
	t_vector	aux;
	t_vector	aux2;

	res = ft_calloc(1, sizeof(t_cam));
	res->data = data;
	res->origin = (t_vector){0, 0, 0};
	res->horizontal = (t_vector){info->viewport_width, 0, 0};
	res->vertical = (t_vector){0, info->viewport_height, 0};
	res->horizontal = vec_div_scalar_apply(res->horizontal, 2.0);
	res->vertical = vec_div_scalar_apply(res->vertical, 2.0);
	aux = add_two_vectors(res->horizontal, res->vertical);
	aux2 = (t_vector){0, 0, info->focal_lenght};
	aux = vec_add_apply(aux, aux2);
	res->lower_left_corner = subtract_two_vectors((t_vector){0, 0, 0}, aux);
	res->horizontal = vec_mul_scalar_apply(res->horizontal, 2.0);
	res->vertical = vec_mul_scalar_apply(res->vertical, 2.0);
	return (res);
}

t_cam_info	*init_cam_info(double w, double h, double fl)
{
	t_cam_info	*new;

	new = (t_cam_info *)malloc(sizeof(t_cam_info));
	if (!new)
		return (NULL);
	new->viewport_width = w;
	new->viewport_height = h;
	new->focal_lenght = fl;
	return (new);
}


