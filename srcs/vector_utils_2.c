/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:07:10 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/07 15:37:09 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

t_vector	*subtract_two_vectors(t_vector *vecA, t_vector *vecB)
{
	t_vector	*vec_sum = 0;

	vec_sum->i = vecA->i - vecB->i;
	vec_sum->j = vecA->j - vecB->j;
	vec_sum->k = vecA->k - vecB->k;
	return (vec_sum);
}

t_vector	*vector_times_scalar(t_vector *vec, double t)
{
	vec->i *= t;
	vec->j *= t;
	vec->k *= t;
	return (vec);
}

t_vector	*create_unit_vector(t_vector *vec)
{
	t_vector	*unit = 0;
	double		magnitude;

	magnitude = vec_magnitude_calc(vec);
	unit->i = vec->i / magnitude;
	unit->j = vec->j / magnitude;
	unit->k = vec->k / magnitude;
	return (unit);
}

double	dot_product_vectors(t_vector *vecA, t_vector *vecB)
{
	return (vecA->i * vecB->i + vecA->j * vecB->j + vecA->k * vecB->k);
}

t_vector	*cross_product_vectors(t_vector *vecA, t_vector *vecB)
{
	t_vector	*res = 0;

	res->i = vecA->j * vecB->k - vecA->k * vecB->j;
	res->j = vecA->k * vecB->i - vecA->i * vecB->k;
	res->k = vecA->i * vecB->j - vecA->j * vecB->i;
	return (res);
}
