/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:58:11 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/12 20:21:09 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ctrl + shift L AND fn + f2
#include "../includes/mlx.h"
#include "../includes/mlx_base.h"
#include "../includes/color.h"
#include "../includes/ray.h"
#include "../includes/vector.h"
#include <stdlib.h>
#include <fcntl.h>

#include "../includes/parser.h"
#include <stdio.h>

static void	print_scene_values(t_scene *scene)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;

	printf("------------------------------------------\n");
	printf("Camera: (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f) (%.1f)\n",
		scene->camera.pos_x, scene->camera.pos_y, scene->camera.pos_z,
		scene->camera.dir_x, scene->camera.dir_y, scene->camera.dir_z,
		scene->camera.fov);
	printf("Ambient: (%.1f) (%.1f, %.1f, %.1f)\n",
		scene->ambient.ratio,
		scene->ambient.col_r, scene->ambient.col_r, scene->ambient.col_r);
	printf("Light: (%.1f, %.1f, %.1f) (%.1f) (%.1f, %.1f, %.1f)\n\n",
		scene->light.pos_x, scene->light.pos_y, scene->light.pos_z,
		scene->light.ratio,
		scene->light.col_r, scene->light.col_r, scene->light.col_r);
	sphere = scene->spheres;
	while (sphere)
	{
		printf("Sphere: (%.1f, %.1f, %.1f) (%.1f) (%.1f, %.1f, %.1f)\n",
			sphere->pos_x, sphere->pos_y, sphere->pos_z,
			sphere->diameter,
			sphere->col_r, sphere->col_g, sphere->col_b);
		sphere = sphere->next;
	}
	plane = scene->planes;
	while (plane)
	{
		printf("Plane: (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f)\n",
			plane->pos_x, plane->pos_y, plane->pos_z,
			plane->dir_x, plane->dir_y, plane->dir_z,
			plane->col_r, plane->col_g, plane->col_b);
		plane = plane->next;
	}
	cylinder = scene->cylinders;
	while (cylinder)
	{
		printf("Cylinder: (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f) (%.1f) (%.1f) (%.1f, %.1f, %.1f)\n",
			cylinder->pos_x, cylinder->pos_y, cylinder->pos_z,
			cylinder->dir_x, cylinder->dir_y, cylinder->dir_z,
			cylinder->diameter,
			cylinder->height,
			cylinder->col_r, cylinder->col_g, cylinder->col_b);
		cylinder = cylinder->next;
	}
	printf("------------------------------------------\n");
}

int main()
{
	int			index;
	double		aspect_ratio;
	int			image_width;
	int			image_height;
	double		viewboard_height;
	double		viewboard_width;
	double		focal_length;
	t_mlx		mlx;
	t_point		*origin;
	t_vector	*horizontal;
	t_vector	*vertical;
	t_vector	*lower_left_corner;
	t_ray		*ray;
	t_color		*pixel_color;

	int scene_file = open("test.rt", O_RDONLY);
	t_scene *scene = parse_scene_file(scene_file);
	print_scene_values(scene);

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_HEIGHT, WIN_WIDTH, "MiniRT");

	// Image
	aspect_ratio = 16.0 / 9.0;
	image_width = 400;
	image_height = (int)(image_width / aspect_ratio);

	// Camera
	viewboard_height = 2.0;
	viewboard_width = aspect_ratio * viewboard_height;
	focal_length = 1.0;

	origin = new_point(0, 0, 0);
	horizontal = vec_create(viewboard_width, 0, 0);
	vertical = vec_create(0, viewboard_height, 0);
	lower_left_corner = subtract_two_vectors(subtract_two_vectors((t_vector *)origin,
				vector_times_scalar(horizontal, 0.5)),
			subtract_two_vectors(vector_times_scalar(vertical, 0.5),
				vec_create(0, 0, focal_length)));

	// Render
	mlx.img->img_ptr = mlx_new_image(mlx.mlx_ptr, image_width, image_height);
	mlx.img->addr = mlx_get_data_addr(mlx.img->img_ptr, &mlx.img->bpp,
			&mlx.img->size_l, &mlx.img->endian);
	index = 0;
	for (int j = image_height-1; j >= 0; --j)
	{
		for (int i = 0; i < image_width; ++i)
		{
			double u = (double)i / (image_width - 1);
			double v = (double)j / (image_height - 1);
			ray = new_ray(origin, add_two_vectors(lower_left_corner,
						add_two_vectors(vector_times_scalar(horizontal, u),
							vector_times_scalar(vertical, v))));
			pixel_color = ray_color(ray);
			mlx.img->addr[index] = (char)(pixel_color->r * 255.999);
			mlx.img->addr[index + 1] = (char)(pixel_color->g * 255.999);
			mlx.img->addr[index + 2] = (char)(pixel_color->b * 255.999);
			index += 4;
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
