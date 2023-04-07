/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 08:32:04 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/07 14:29:02 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct s_vector
{
	float	i;
	float	j;
	float	k;
}	t_vector;

t_vector	*vec_create(float x, float y, float z);
t_vector	*negative_of_vec(t_vector *vec);
double		vec_lenght_squared(t_vector *vec);
double		vec_magnitude_calc(t_vector *vec);
t_vector	*add_two_vectors(t_vector *vecA, t_vector *vecB);
t_vector	*subtract_two_vectors(t_vector *vecA, t_vector *vecB);
t_vector	*vector_times_scalar(t_vector *vec, double t);
t_vector	*create_unit_vector(t_vector *vec);
double		dot_product_vectors(t_vector *vecA, t_vector *vecB);
t_vector	*cross_product_vectors(t_vector *vecA, t_vector *vecB);

#endif
