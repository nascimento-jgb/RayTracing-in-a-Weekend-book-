/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:44:32 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/13 12:50:40 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt_struct.h"

t_vector	vec_create(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vector	negative_of_vec(t_vector vec)
{
	vec.x *= -1;
	vec.y *= -1;
	vec.z *= -1;
	return (vec);
}

double	vec_lenght_squared(t_vector vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vec_magnitude_calc(t_vector vec)
{
	return (sqrt(vec_lenght_squared(vec)));
}

t_vector	*add_two_vectors(t_vector vecA, t_vector vecB)
{
	t_vector	vec_sum;

	vec_sum.x = vecA.x + vecB.x;
	vec_sum.y = vecA.y + vecB.y;
	vec_sum.z = vecA.z + vecB.z;
	return (vec_sum);
}
