/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:44:42 by helneff           #+#    #+#             */
/*   Updated: 2023/04/18 12:27:38 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "libft.h"

int	parse_ambient(t_scene_data *scene, const char *elem)
{
	static int	first = 1;

	if (!first)
		return (1);
	first = 0;
	if (parse_num(&elem, &scene->ambient.ratio) || eat_whitespace(&elem)
		|| parse_num(&elem, &scene->ambient.col_r) || eat_comma(&elem)
		|| parse_num(&elem, &scene->ambient.col_g) || eat_comma(&elem)
		|| parse_num(&elem, &scene->ambient.col_b) || (*elem && *elem != '\n')
		|| scene->ambient.ratio < 0 || scene->ambient.ratio > 1
		|| scene->ambient.col_r < 0 || scene->ambient.col_r > 255
		|| scene->ambient.col_g < 0 || scene->ambient.col_g > 255
		|| scene->ambient.col_b < 0 || scene->ambient.col_b > 255)
		return (1);
	return (0);
}
