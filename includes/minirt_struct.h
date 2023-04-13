/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:38:56 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/13 13:10:03 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include <math.h>

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;


//Vector
t_vector	vec_create(double x, double y, double z);
t_vector	negative_of_vec(t_vector vec);
double		vec_lenght_squared(t_vector vec);
double		vec_magnitude_calc(t_vector vec);
t_vector	add_two_vectors(t_vector vecA, t_vector vecB);
t_vector	subtract_two_vectors(t_vector vecA, t_vector vecB);
t_vector	vector_multiply_scalar(t_vector vec, double t);
t_vector	create_unit_vector(t_vector vec);
double		dot_product_vectors(t_vector vecA, t_vector vecB);
t_vector	cross_product_vectors(t_vector vecA, t_vector vecB);

//Ray
t_vector	new_point(double x, double y, double z);
t_ray		new_ray(t_vector orig, t_vector dir);
t_vector	ray_at(t_ray ray, double t);
t_vector	ray_color(t_ray ray);

//Color
void		write_color_screen(t_mlx *scene, int x, int y, t_vector color);
t_vector	color_new(double r, double g, double b);
t_vector	color_multiply_scalar(t_vector color, double num);
t_vector	color_add(t_vector colorA, t_vector colorB);

#endif
