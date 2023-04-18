/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:54:07 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/18 15:01:43 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

t_img_data	create_img_data(int width, int height)
{
	t_img_data	new;
	int			i;
	int			j;

	new.img_width = width;
	new.img_height = height;
	new.ref = (int **)malloc(sizeof(int *) * width);
	i = -1;
	while (++i < width)
	{
		j = -1;
		new.ref[i] = (int *)malloc(sizeof(int) * height);
		while (++j < height)
			new.ref[i][j] = 0;
	}
	return (new);
}
