/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:59:42 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/14 15:52:51 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt_mlx.h"

t_vector	*vec_add_apply(t_vector *vecA, t_vector *vecB)
{
	vecA->x += vecB->x;
	vecA->y += vecB->y;
	vecA->z += vecB->z;
	return (vecA);
}

t_vector	*vec_sub_apply(t_vector *vecA, t_vector *vecB)
{
	vecA->x -= vecB->x;
	vecA->y -= vecB->y;
	vecA->z -= vecB->z;
	return (vecA);
}

t_vector	*vec_mul_scalar_apply(t_vector *vecA, double c)
{
	vecA->x *= c;
	vecA->y *= c;
	vecA->z *= c;
	return (vecA);
}

t_vector	*vec_div_scalar_apply(t_vector *vecA, double c)
{
	vecA->x /= c;
	vecA->y /= c;
	vecA->z /= c;
	return (vecA);
}

t_vector	*vec_unit_apply(t_vector *vecA)
{
	return (vec_div_scalar_apply(vecA, vec_magnitude_calc(vecA)));
}
