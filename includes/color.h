/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:30:49 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/07 14:26:18 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "mlx.h"
# include "mlx_base.h"
# include "vector.h"

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

void	write_color_screen(t_mlx *image, int x, int y, t_color color);
t_color	*color_new(double r, double g, double b);
t_color	*color_multiply_scalar(t_color *color, double num);
t_color	*color_add(t_color *colorA, t_color *colorB);

#endif
