/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:49:04 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/14 11:19:03 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MLX_H
# define MINIRT_MLX_H

# include "mlx.h"
# include "minirt_struct.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_mlx_data
{
	void	*img_ptr;
	char	*addr;
	int		size_l;
	int		bpp;
	int		endian;
}			t_mlx_data;

typedef struct s_img_data
{
	int		img_height;
	int		img_width;
	int		**ref;
}	t_img_data;

typedef struct s_mlx_ptrs
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx_ptrs;

typedef struct s_cam
{
	t_img_data	*img;
	double		aspect_ratio;
	double		viewport_height;
	double		viewport_width;
	double		focal_lenght;
	t_vector	origin;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	lower_left_corner;
}	t_cam;


//Calc utils
double		blend(double x, double min, double max);
double		get_radian(double degree);

//Color Utils
int			get_color_val(t_vector *color);
int			get_color_sample_gamma(t_vector *color);
t_vector	*get_color(int rgb);

// Img data utils
t_img_data	*create_img_data(int width, int height);
void		free_img_data(t_img_data *program);

// mlx utils
int			exit_program(int flag);
int			mlx_key_handle(int keycode);
void		mlx_draw_by_img_data(t_mlx_data *prog, t_img_data *data);
void		mlx_show(t_img_data *data, char *title);
int			mlx_exec(t_img_data *data, char *name);

//Draw Utils
void		draw_image(t_img_data *data);
void		draw_vertical_line(t_img_data *data, int x);
void		drwa_horizontal_line(t_img_data *data, int y);

#endif
