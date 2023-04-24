/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:57:43 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 13:08:40 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

t_cylinder	*init_cylinder(t_vector center, t_vector axis,
			double height, double radius)
{
	t_cylinder	*new;

	new = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!new)
		return (NULL);
	new->center = center;
	new->axis = axis;
	new->height = height;
	new->radius = radius;
	return (new);
}
