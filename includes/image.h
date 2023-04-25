/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helneff <helneff@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:20:28 by helneff           #+#    #+#             */
/*   Updated: 2023/04/24 21:09:55 by helneff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "window.h"

typedef struct s_image
{
	void	*mlx_img;
	char	*buffer;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		width;
	int		height;
}	t_image;

int		init_image(t_image *img, const t_window *window);
void	set_pixel(t_image *img, int x, int y, int color);
void	fill_color(t_image *img, int color);

#endif
