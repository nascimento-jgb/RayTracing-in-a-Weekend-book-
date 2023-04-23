/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hittable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:06:16 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/23 15:12:49 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

int	hittable_color(t_list *list, t_hitlst_info *info)
{
	t_vector	color;
	t_vector	aux;
	t_vector	aux2;
	double		t;

	if (hitlst_hit(list, info))
	{
		color = add_two_vectors((t_vector){1, 1, 1}, info->rec->normal);
		color = vec_mul_scalar_apply(color, 0.5);
	}
	else
	{
		aux = create_unit_vector(info->ray->direction);
		t = 0.5 * (aux.y + 1.0);
		color = vec_mul_scalar((t_vector){1, 1, 1}, 1.0 - t);
		aux2 = vec_mul_scalar((t_vector){0.5, 0.7, 1}, t);
		color = vec_add_apply(color, aux2);
	}
	return (get_color_val(color));
}

void	hittable_draw(t_cam *cam, t_list *list)
{
	t_hitlst_info	*list_info;
	int				x;
	int				y;
	int				i;
	int				j;

	y = cam->data->img_height - 1;
	while (--y >= 0)
	{
		x = -1;
		while (++x < cam->data->img_width)
		{
			i = (double)x / (cam->data->img_width - 1);
			j = (double)y / (cam->data->img_height - 1);
			list_info = hitlst_info_new(camera_get_ray(cam, i, j));
			cam->data->ref[x][y] = hittable_color(list, list_info);
			free(list_info);
		}
	}
}

t_hittable	*hittable_new(void *obj, int obj_type)
{
	t_hittable	*res;

	res = (t_hittable *)malloc(sizeof(t_hittable));
	if (!res)
		return (res);
	res->obj = obj;
	res->obj_type = obj_type;
	if (obj_type == OBJ_SPHERE)
		res->hit = &sphere_hit;
	return (res);
}
