/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:35:18 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/07 15:41:36 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector.h"

t_vector	*vec_create(float i, float j, float k)
{
	t_vector	*vec = 0;

	vec->i = i;
	vec->j = j;
	vec->k = k;
	return (vec);
}

t_vector	*negative_of_vec(t_vector *vec)
{
	vec->i *= -1;
	vec->j *= -1;
	vec->k *= -1;
	return (vec);
}

double	vec_lenght_squared(t_vector *vec)
{
	return (vec->i * vec->i + vec->j * vec->j + vec->k * vec->k);
}

double	vec_magnitude_calc(t_vector *vec)
{
	return (sqrt(vec_lenght_squared(vec)));
}

t_vector	*add_two_vectors(t_vector *vecA, t_vector *vecB)
{
	t_vector	*vec_sum = 0;

	vec_sum->i = vecA->i + vecB->i;
	vec_sum->j = vecA->j + vecB->j;
	vec_sum->k = vecA->k + vecB->k;
	return (vec_sum);
}
