/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:49:39 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/13 13:02:37 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt_struct.h"

t_vector	subtract_two_vectors(t_vector vecA, t_vector vecB)
{
	t_vector	vec_sum;

	vec_sum.x = vecA.x - vecB.x;
	vec_sum.y = vecA.y - vecB.y;
	vec_sum.z = vecA.z - vecB.z;
	return (vec_sum);
}

t_vector	vector_multiply_scalar(t_vector vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_vector	create_unit_vector(t_vector vec)
{
	t_vector	unit;
	double		magnitude;

	magnitude = vec_magnitude_calc(vec);
	unit.x = vec.x / magnitude;
	unit.y = vec.y / magnitude;
	unit.z= vec.z / magnitude;
	return (unit);
}

double	dot_product_vectors(t_vector vecA, t_vector vecB)
{
	return (vecA.x * vecB.x + vecA.y * vecB.y + vecA.z * vecB.z);
}

t_vector	cross_product_vectors(t_vector vecA, t_vector vecB)
{
	t_vector	res;

	res.x = vecA.y * vecB.z - vecA.z * vecB.y;
	res.y = vecA.z * vecB.x - vecA.x * vecB.z;
	res.z = vecA.x * vecB.y - vecA.y * vecB.x;
	return (res);
}
