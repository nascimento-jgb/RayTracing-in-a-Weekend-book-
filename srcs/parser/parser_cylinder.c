/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:42 by helneff           #+#    #+#             */
/*   Updated: 2023/04/12 19:02:33 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

#include "../../includes/libft.h"

int	parse_cylinder(t_scene_data *scene, const char *elem)
{
	t_cylinder_data	*cylinder;

	cylinder = malloc(sizeof(t_cylinder_data));
	if (!cylinder)
		return (1);
	if (parse_num(&elem, &cylinder->pos_x) || eat_comma(&elem)
		|| parse_num(&elem, &cylinder->pos_y) || eat_comma(&elem)
		|| parse_num(&elem, &cylinder->pos_z) || eat_whitespace(&elem)
		|| parse_num(&elem, &cylinder->dir_x) || eat_comma(&elem)
		|| parse_num(&elem, &cylinder->dir_y) || eat_comma(&elem)
		|| parse_num(&elem, &cylinder->dir_z) || eat_whitespace(&elem)
		|| parse_num(&elem, &cylinder->diameter) || eat_whitespace(&elem)
		|| parse_num(&elem, &cylinder->height) || eat_whitespace(&elem)
		|| parse_num(&elem, &cylinder->col_r) || eat_comma(&elem)
		|| parse_num(&elem, &cylinder->col_g) || eat_comma(&elem)
		|| parse_num(&elem, &cylinder->col_b) || (*elem && *elem != '\n')
		|| cylinder->dir_x < -1 || cylinder->dir_x > 1 || cylinder->dir_y < -1
		|| cylinder->dir_y > 1 || cylinder->dir_z < -1 || cylinder->dir_z > 1
		|| cylinder->col_r < 0 || cylinder->col_r > 255
		|| cylinder->col_g < 0 || cylinder->col_g > 255
		|| cylinder->col_b < 0 || cylinder->col_b > 255)
		return (free(cylinder), 1);
	cylinder->next = scene->cylinders;
	scene->cylinders = cylinder;
	return (0);
}
