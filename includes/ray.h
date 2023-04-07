/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:31:49 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/07 15:36:58 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"
# include "color.h"

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_ray
{
	t_point		*origin;
	t_vector	*direction;
}		t_ray;

t_point		*new_point(double x, double y, double z);
t_ray		*new_ray(t_point *orig, t_vector *dir);
t_vector	*ray_at(t_ray *ray, double t);
t_color		*ray_color(const t_ray *ray);

#endif
