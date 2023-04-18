/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:42 by helneff           #+#    #+#             */
/*   Updated: 2023/04/17 12:38:42 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

#include "../../includes/libft.h"

int	parse_camera(t_scene_data *scene, const char *elem)
{
	static int	first = 1;

	if (!first)
		return (1);
	first = 0;
	if (parse_num(&elem, &scene->camera.pos_x) || eat_comma(&elem)
		|| parse_num(&elem, &scene->camera.pos_y) || eat_comma(&elem)
		|| parse_num(&elem, &scene->camera.pos_z) || eat_whitespace(&elem)
		|| parse_num(&elem, &scene->camera.dir_x) || eat_comma(&elem)
		|| parse_num(&elem, &scene->camera.dir_y) || eat_comma(&elem)
		|| parse_num(&elem, &scene->camera.dir_z) || eat_whitespace(&elem)
		|| parse_num(&elem, &scene->camera.fov) || (*elem && *elem != '\n')
		|| scene->camera.dir_x < -1 || scene->camera.dir_x > 1
		|| scene->camera.dir_y < -1 || scene->camera.dir_y > 1
		|| scene->camera.dir_z < -1 || scene->camera.dir_z > 1
		|| scene->camera.fov < 0 || scene->camera.fov > 180)
		return (1);
	return (0);
}
