/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:58:02 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 13:47:06 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

int	cylinder_hit(void *cy, t_ray *ray, t_hitlst_info *info, t_hit_record *rec)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	oc = subtract_two_vectors(ray->origin, ((t_cylinder *)cy)->center);
	a = dot_product_vectors(ray->direction, ray->direction) - pow(dot_product_vectors(ray->direction, ((t_cylinder *)cy)->axis), 2);
	b = 2 * (dot_product_vectors(ray->direction, oc) - dot_product_vectors(ray->direction, ((t_cylinder *)cy)->axis) * dot_product_vectors(oc, ((t_cylinder *)cy)->axis));
	c = dot_product_vectors(oc, oc) - pow(dot_product_vectors(oc, ((t_cylinder *)cy)->axis), 2) - pow(((t_cylinder *)cy)->radius, 2);
	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		return (FALSE);

	double	t1 = (-b - sqrt(discriminant)) / (2 * a);
	double	t2 = (-b + sqrt(discriminant)) / (2 * a);
	double	t = -1;
	if (t1 >= info->t_min && t1 <= info->t_max)
		t = t1;
	else if (t2 >= info->t_min && t2 <= info->t_max)
		t = t2;
	else
		return (FALSE);

	t_vector	p;
	double		y;
	p = ray_at(ray, t);
	y = dot_product_vectors(vec_sub_apply(p, ((t_cylinder *)cy)->center), ((t_cylinder *)cy)->axis);

	if (y < 0 || y > ((t_cylinder *)cy)->height)
		return (FALSE);
	rec->t = t;
	rec->point = p;
	rec->normal = create_unit_vector(vec_sub_apply(p, vec_add_apply(((t_cylinder *)cy)->center, vec_mul_scalar_apply(((t_cylinder *)cy)->axis, y))));
	return(TRUE);
}
