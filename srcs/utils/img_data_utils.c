/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:54:07 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/18 12:27:38 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_mlx.h"

t_img_data	*create_img_data(int width, int height)
{
	t_img_data	*new;
	int			i;
	int			j;

	new = (t_img_data *)malloc(sizeof(t_img_data));
	if (!new)
		return (NULL);
	new->img_width = width;
	new->img_height = height;
	new->ref = (int **)malloc(sizeof(int *) * width);
	i = -1;
	while (++i < width)
	{
		j = -1;
		new->ref[i] = (int *)malloc(sizeof(int) * height);
		while (++j < height)
			new->ref[i][j] = 0;
	}
	return (new);
}

void	free_img_data(t_img_data *data)
{
	int	i;

	i = -1;
	while (++i < data->img_width)
		free(data->ref[i]);
	free(data->ref);
}
