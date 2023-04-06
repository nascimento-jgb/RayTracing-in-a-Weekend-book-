/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:08:34 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/06 13:29:05 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/example.h"

int	main(void)
{
	t_mlx	mlx;
	int		count_w;
	int		count_h;

	count_h = -1;
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);

	/*
	 Now the important part :
	 mlx_get_data_addr will return a char* that is 4 times the (width * height) of your image.
	 Why so ? Let me explain : This char* will represent your image, pixel by pixel,
	 and the values of this array are the colors. That's why the array is 4 times bigger :
	 you need 4 char to code the color of each pixels (one for Red, Green and Blue) and one for the alpha.
	 But... it's not very convenient, right ? So here is my little trick : you cast
	 mlx_get_data_addr as an int* and store it in an int*.
	 This way, the array will have the exact same size as your window, and each index
	 will represent one complete color of a pixel !
	*/

	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);

	/*
	 Now just a little example : here is a loop that will draw each pixels that
	 have an odd width in white and the ones that have an even width in black.
	*/

	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			// float t = (float)count_w / WIN_WIDTH; // calculate current position as a float between 0 and 1
			float	r, g, b;

			r = (count_w / WIN_WIDTH - 1);
			g = (count_h / WIN_HEIGHT - 1);
			b = 0.25;

			int ir, ig, ib;
			//RETURN HERE
			r = (count_w / WIN_WIDTH - 1);
			g = (count_h / WIN_HEIGHT - 1);
			b = 0.25;

			// if (t < 0.5f)
			// {
			// 	// calculate red and green components (increase from 0 to 255)
			// 	r = (int)(255 * (t * 2));
			// 	g = (int)(255 * (t * 2));
			// 	b = 0;
        	// }
			// else
			// {
			// 	// calculate green and blue components (decrease from 255 to 0)
			// 	r = 0;
			// 	g = (int)(255 * ((1 - t) * 2));
			// 	b = (int)(255 * ((1 - t) * 2));
			// }
			int hex_color = (r << 16) | (g << 8) | b; // combine red, green, and blue components into a hex color value
			mlx.img.data[count_h * WIN_WIDTH + count_w] = hex_color;
			// if (count_w % 2)
			// 	/*
			// 	 As you can see here instead of using the mlx_put_pixel function
			// 	 I just assign a color to each pixel one by one in the image,
			// 	 and the image will be printed in one time at the end of the loop.
			// 	 Now one thing to understand here is that you're working on a 1-dimensional
			// 	 array, while your window is (obviously) 2-dimensional.
			// 	 So, instead of having data[height][width] here you'll have the following
			// 	 formula : [current height * max width + current width] (as you can see below)
			//mlx.img.data[count_h * WIN_WIDTH + count_w] = hex_color;
			// 	*/
			// 	mlx.img.data[count_h * WIN_WIDTH + count_w] = hex_color;
			// else
			// 	mlx.img.data[count_h * WIN_WIDTH + count_w] = 0;
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
