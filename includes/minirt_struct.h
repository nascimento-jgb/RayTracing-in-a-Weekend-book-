/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:38:56 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 13:09:10 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

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

typedef struct s_sphere
{
	t_vector	center;
	double		radius;
}	t_sphere;

typedef struct s_plane
{
	t_vector	normal;
	t_vector	point;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	center;
	t_vector	axis;
	double		height;
	double		radius;
}	t_cylinder;

//Vector
t_vector	negative_of_vec(t_vector vec);
t_vector	vec_mul_scalar(t_vector vec, double num);
double		vec_lenght_squared(t_vector vec);
double		vec_magnitude_calc(t_vector vec);

//vector2
t_vector	add_two_vectors(t_vector vecA, t_vector vecB);
t_vector	subtract_two_vectors(t_vector vecA, t_vector vecB);
t_vector	create_unit_vector(t_vector vec);
double		dot_product_vectors(t_vector vecA, t_vector vecB);
t_vector	cross_product_vectors(t_vector vecA, t_vector vecB);

//vector3
t_vector	vec_add_apply(t_vector vecA, t_vector vecB);
t_vector	vec_sub_apply(t_vector vecA, t_vector vecB);
t_vector	vec_mul_scalar_apply(t_vector vecA, double c);
t_vector	vec_div_scalar_apply(t_vector vecA, double c);
t_vector	vec_unit_apply(t_vector vecA);

//Ray
t_vector	ray_at(t_ray *ray, double t);
int			atribute_color_to_ray(t_ray *ray);

//Sphere
int			ray_hit_sphere(t_sphere *sphere, t_ray *ray);
double		ray_hit_sphere2(t_sphere *sphere, t_ray *ray);
t_sphere	*init_sphere(t_vector center, double radius);
int			atribute_color_to_ray2(t_sphere *sphere, t_ray *ray);

//Plane
t_plane		*init_plane(t_vector normal, t_vector point);

//Cylinder
t_cylinder	*init_cylinder(t_vector center, t_vector axis,
				double height, double radius);

#endif
