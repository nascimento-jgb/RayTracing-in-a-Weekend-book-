/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:02:57 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 11:38:01 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

int	plane_hit(void *plane, t_ray *ray, t_hitlst_info *info, t_hit_record *rec)
{
	t_vector	to_plane;
	double		denom;
	double		t;

	denom = dot_product_vectors(ray->direction, ((t_plane *)plane)->normal);
	if (fabs(denom) < 1e-6)
		return (FALSE); // Ray is parallel to plane
	to_plane = subtract_two_vectors(((t_plane *)plane)->point, ray->origin);
	t = dot_product_vectors(to_plane, ((t_plane *)plane)->normal) / denom;
	if (t < info->t_min || t > info->t_max)
		return (FALSE);
	rec->t = t;
	rec->point = ray_at(ray, t);
	rec->normal = ((t_plane *)plane)->normal;
	return (TRUE);
}
