/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:33:21 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 09:50:48 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

t_hit_record	*hit_record_new(void)
{
	t_hit_record	*new;

	new = ft_calloc(1, sizeof(t_hit_record));
	if (!new)
		return (NULL);
	return (new);
}

void	hit_set_normal(t_hit_record *record, t_ray *ray)
{
	double	res;

	res = dot_product_vectors(ray->direction, record->normal);
	if (res < 0)
		record->front_face_flag = TRUE;
	else
	{
		record->front_face_flag = FALSE;
		record->normal = vec_mul_scalar_apply(record->normal, -1);
	}
}

