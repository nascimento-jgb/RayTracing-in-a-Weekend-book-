/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:42 by helneff           #+#    #+#             */
/*   Updated: 2023/04/17 12:39:14 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

#include "../../includes/libft.h"

int	parse_sphere(t_scene_data *scene, const char *elem)
{
	t_sphere_data	*sphere;

	sphere = malloc(sizeof(t_sphere_data));
	if (!sphere)
		return (1);
	if (parse_num(&elem, &sphere->pos_x) || eat_comma(&elem)
		|| parse_num(&elem, &sphere->pos_y) || eat_comma(&elem)
		|| parse_num(&elem, &sphere->pos_z) || eat_whitespace(&elem)
		|| parse_num(&elem, &sphere->diameter) || eat_whitespace(&elem)
		|| parse_num(&elem, &sphere->col_r) || eat_comma(&elem)
		|| parse_num(&elem, &sphere->col_g) || eat_comma(&elem)
		|| parse_num(&elem, &sphere->col_b) || (*elem && *elem != '\n')
		|| sphere->col_r < 0 || sphere->col_r > 255
		|| sphere->col_g < 0 || sphere->col_g > 255
		|| sphere->col_b < 0 || sphere->col_b > 255)
		return (free(sphere), 1);
	sphere->next = scene->spheres;
	scene->spheres = sphere;
	return (0);
}
