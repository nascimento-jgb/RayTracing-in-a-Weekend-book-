/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:49:04 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 13:49:45 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MLX_H
# define MINIRT_MLX_H

# include "mlx.h"
# include "minirt_struct.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

# define FALSE	0
# define TRUE	1

# define OBJ_SPHERE		1
# define OBJ_PLANE		2
# define OBJ_CYLINDER	3

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
	double	aspect_ratio;
	int		img_height;
	int		img_width;
	int		**ref;
}	t_img_data;

typedef struct s_mlx_ptrs
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx_ptrs;

typedef struct s_cam_info
{
	double		viewport_height;
	double		viewport_width;
	double		focal_lenght;
}	t_cam_info;

typedef struct s_cam
{
	t_img_data	*data;
	t_vector	origin;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	lower_left_corner;
}	t_cam;

typedef struct s_hit_record
{
	t_vector	point;
	t_vector	normal;
	double		t;
	int			front_face_flag;
}	t_hit_record;

typedef struct s_hitlst_info
{
	t_ray			*ray;
	t_hit_record	*rec;
	double			t_min;
	double			t_max;
	double			a;
	double			half_b;
	double			root_d;
}	t_hitlst_info;

typedef struct s_hittable
{
	void	*obj;
	int		obj_type;
	int		hit;
}	t_hittable;

//Calc utils
double			blend(double x, double min, double max);
double			get_radian(double degree);

//Color Utils
int				get_color_val(t_vector color);
int				get_color_sample_gamma(t_vector color);
t_vector		get_color(int rgb);

// Img data utils
t_img_data		*create_img_data(int width, int height);
void			free_all(t_img_data *data, t_cam_info *info, t_sphere *s);

// mlx utils
int				exit_program(void);
int				mlx_key_handle(int keycode);
void			mlx_draw_by_img_data(t_mlx_data *prog, t_img_data *data);
int				mlx_exec(t_img_data *data, char *name);

//Draw Utils
void			draw_image(t_img_data *data);
void			draw_vertical_line(t_img_data data, int x);
void			draw_horizontal_line(t_img_data data, int y);
void			draw_sphere(t_img_data *data, t_cam_info *info,
					t_sphere *sphere);
void			draw_sphere2(t_img_data *data, t_cam_info *info,
					t_sphere *sphere);

//Cam Image
t_cam_info		*init_cam_info(double w, double h, double fl);
t_cam			*init_cam_struct( t_img_data *data, t_cam_info *info);
void			create_sky_image(t_img_data *data, t_cam_info *info);
t_ray			*camera_get_ray(t_cam *cam, double u, double v);
t_ray			*render_ray(int x, int y, t_cam *visual);

//Sphere Hit
int				sphere_hit(void *sphere, t_ray *ray, t_hitlst_info *info,
					t_hit_record *rec);
int				check_sphere_hitrange(t_sphere *sphere, t_ray *ray,
					t_hitlst_info *info, t_hit_record *rec);

//Plane hit
int				plane_hit(void *plane, t_ray *ray, t_hitlst_info *info,
					t_hit_record *rec);

//Cylinder hit
int	cylinder_hit(void *cy, t_ray *ray, t_hitlst_info *info, t_hit_record *rec);

//Hit Record
t_hit_record	*hit_record_new(void);
void			hit_set_normal(t_hit_record *record, t_ray *ray);

//Hittable
t_hittable		*hittable_new(void *obj, int obj_type);
void			hittable_draw(t_cam *cam, t_list *list);
int				hittable_color(t_list *list, t_hitlst_info *info);

//Hit List Utils
int				hitlst_hit(t_list *list, t_hitlst_info *info);
t_list			*hitlst_new(void);
void			hitlst_add(t_list *list, void *obj, int obj_type);
// void			hitlist_free(t_list *list);

//Hit List Info Utils
t_hitlst_info	*hitlst_info_new(t_ray *ray);

#endif
