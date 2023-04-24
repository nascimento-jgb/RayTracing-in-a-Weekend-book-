/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:58:11 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/24 10:05:21 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"
#include "parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

// static void	print_scene_values(t_scene *scene)
// {
// 	t_sphere	*sphere;
// 	t_plane		*plane;
// 	t_cylinder	*cylinder;

// 	printf("------------------------------------------\n");
// 	printf("Camera: (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f) (%.1f)\n",
// 		scene->camera.pos_x, scene->camera.pos_y, scene->camera.pos_z,
// 		scene->camera.dir_x, scene->camera.dir_y, scene->camera.dir_z,
// 		scene->camera.fov);
// 	printf("Ambient: (%.1f) (%.1f, %.1f, %.1f)\n",
// 		scene->ambient.ratio,
// 		scene->ambient.col_r, scene->ambient.col_r, scene->ambient.col_r);
// 	printf("Light: (%.1f, %.1f, %.1f) (%.1f) (%.1f, %.1f, %.1f)\n\n",
// 		scene->light.pos_x, scene->light.pos_y, scene->light.pos_z,
// 		scene->light.ratio,
// 		scene->light.col_r, scene->light.col_r, scene->light.col_r);
// 	sphere = scene->spheres;
// 	while (sphere)
// 	{
// 		printf("Sphere: (%.1f, %.1f, %.1f) (%.1f) (%.1f, %.1f, %.1f)\n",
// 			sphere->pos_x, sphere->pos_y, sphere->pos_z,
// 			sphere->diameter,
// 			sphere->col_r, sphere->col_g, sphere->col_b);
// 		sphere = sphere->next;
// 	}
// 	plane = scene->planes;
// 	while (plane)
// 	{
// 		printf("Plane: (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f)\n",
// 			plane->pos_x, plane->pos_y, plane->pos_z,
// 			plane->dir_x, plane->dir_y, plane->dir_z,
// 			plane->col_r, plane->col_g, plane->col_b);
// 		plane = plane->next;
// 	}
// 	cylinder = scene->cylinders;
// 	while (cylinder)
// 	{
// 		printf("Cylinder: (%.1f, %.1f, %.1f) (%.1f, %.1f, %.1f) (%.1f) (%.1f) (%.1f, %.1f, %.1f)\n",
// 			cylinder->pos_x, cylinder->pos_y, cylinder->pos_z,
// 			cylinder->dir_x, cylinder->dir_y, cylinder->dir_z,
// 			cylinder->diameter,
// 			cylinder->height,
// 			cylinder->col_r, cylinder->col_g, cylinder->col_b);
// 		cylinder = cylinder->next;
// 	}
// 	printf("------------------------------------------\n");
// }

int	main(void)
{
	t_img_data	*image;
	t_cam_info	*visual_info;
	t_sphere2	*sphere;
	t_list		*hit_lst;
	t_cam		*cam;

	// int	scene_file = open("test.rt", O_RDONLY);
	// t_scene	*scene = parse_scene_file(scene_file);
	// print_scene_values(scene);
	image = create_img_data(1280, 720);
	visual_info = init_cam_info(2.0 * (image->aspect_ratio), 2.0, 1.0);
	cam = init_cam_struct(image, visual_info);
	// draw_image(image); // gradient draw
	// create_sky_image(image, visual_info); //blue and white blending gradient draw
	hit_lst = hitlst_new();
	sphere = init_sphere((t_vector){0, -105.1, -1}, 100);
	hitlst_add(hit_lst, (void *)sphere, OBJ_SPHERE);
	sphere = init_sphere((t_vector){0, 0, -1}, 0.5);
	hitlst_add(hit_lst, (void *)sphere, OBJ_SPHERE);
	hittable_draw(cam, hit_lst);
	// draw_sphere(image, visual_info, sphere); //drawing without normals
	// draw_sphere2(image, visual_info, sphere); //drawing with normal vectors
	mlx_exec(image, "miniRT");
	free_all(image, visual_info, sphere);
	free(hit_lst);
	return (0);
}
