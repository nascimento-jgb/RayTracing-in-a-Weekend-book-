/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:33:34 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 10:12:05 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

int	check_sphere_hitrange(t_sphere2 *sphere, t_ray *ray,
				t_hitlst_info *info, t_hit_record *rec)
{
	int		flag;
	double	t;

	flag = -1;
	while ((++flag) < 2)
	{
		if (flag)
			t = ((info->half_b * -1) + info->root_d) / info->a;
		else
			t = ((info->half_b * -1) - info->root_d) / info->a;
		if (info->t_min < t && t < info->t_max)
		{
			rec->t = t;
			rec->point = ray_at(ray, t);
			rec->normal = subtract_two_vectors(rec->point,
					((t_sphere2 *)sphere)->center);
			rec->normal = vec_div_scalar_apply(rec->normal,
					((t_sphere2 *)sphere)->radius);
			hit_set_normal(rec, ray);
			return (TRUE);
		}
	}
	return (FALSE);
}

int	sphere_hit(void *sphere, t_ray *ray, t_hitlst_info *info, t_hit_record *rec)
{
	t_vector	oc;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;

	oc = subtract_two_vectors(ray->origin, ((t_sphere2 *)sphere)->center);
	a = vec_lenght_squared(ray->direction);
	half_b = dot_product_vectors(oc, ray->direction);
	c = vec_lenght_squared(oc);
	c -= pow(((t_sphere2 *)sphere)->radius, 2);
	discriminant = (half_b * half_b) - (a * c);
	if (discriminant < 0)
		return (FALSE);
	info->a = a;
	info->half_b = half_b;
	info->root_d = sqrt(discriminant);
	return (check_sphere_hitrange(sphere, ray, info, rec));
}
