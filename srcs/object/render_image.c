/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:43:41 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/15 15:12:03 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt_mlx.h"

void	free_cam(t_cam *visual, int is_origin_free)
{
	free(visual->horizontal);
	free(visual->vertical);
	free(visual->lower_left_corner);
	if (is_origin_free)
		free(visual->origin);
	free(visual);
}

int	atribute_color_to_ray(t_ray *ray)
{
	t_vector	*aux;
	t_vector	*aux2;
	double		t;
	int			new;

	aux = create_unit_vector(ray->direction);
	t = 0.5 * (aux->y + 1.0);
	free(aux);
	aux = vec_mul_scalar_apply(vec_create(1, 1, 1), 1.0 - t);
	aux2 = vec_mul_scalar_apply(vec_create(0.5, 0.7, 1), t);
	vec_add_apply(aux, aux2);
	free(aux2);
	new = get_color_val(aux);
	free(aux);
	return (new);
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

t_cam	*init_cam_struct(t_cam_info *info, t_vector *origin)
{
	t_cam		*new;
	t_vector	*aux;
	t_vector	*aux2;
	t_vector	*aux3;

	new = (t_cam *)malloc(sizeof(t_cam));
	if (!new)
		return (NULL);
	new->origin = origin;
	new->horizontal = vec_create(info->viewport_width, 0, 0);
	new->vertical = vec_create(0, info->viewport_height, 0);
	vec_div_scalar_apply(new->horizontal, 2.0);
	vec_div_scalar_apply(new->vertical, 2.0);
	aux = add_two_vectors(new->horizontal, new->vertical);
	aux2 = vec_create(0, 0, info->focal_lenght);
	aux3 = add_two_vectors(aux, aux2);
	new->lower_left_corner = subtract_two_vectors(origin, aux3);
	free(aux);
	free(aux2);
	free(aux3);
	vec_mul_scalar_apply(new->horizontal, 2.0);
	vec_mul_scalar_apply(new->vertical, 2.0);
	return (new);
}

void	create_render_image(t_img_data *data, t_cam_info *info)
{
	t_cam	*visual;
	t_ray	*ray;
	int		i;
	int		j;

	visual = init_cam_struct(info, vec_create(0, 0, 0));
	visual->img = data;
	j = data->img_height;
	while (--j >= 0)
	{
		i = -1;
		while (++i < data->img_width)
		{
			ray = render_ray(i, j, visual);
			data->ref[i][j] = atribute_color_to_ray(ray);
			free_ray(ray, FALSE);
		}
	}
	free_cam(visual, TRUE);
}
