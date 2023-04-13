/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:49:04 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/13 13:11:05 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MLX_H
# define MINIRT_MLX_H


# include "mlx.h"
# include "minirt_struct.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

typedef struct s_img
{
	int		*addr;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_height;
	int		img_width;
}			t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_img	img_data;
	t_cam	cam_data;
}				t_mlx;

typedef struct s_cam
{
	double		aspect_ratio;
	double		viewport_height;
	double		viewport_width;
	double		focal_lenght;
	t_vector	origin;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	lower_left_corner;
}	t_cam;

#endif
