/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:58:02 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 13:20:38 by jonascim         ###   ########.fr       */
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
	b =
}
