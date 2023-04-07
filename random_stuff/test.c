/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:57:29 by jonascim          #+#    #+#             */
/*   Updated: 2023/04/06 11:07:46 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	const int	image_width = 256;
	const int	image_height = 256;
	int			j = image_height - 1;
	int			i = 0;

	printf("P3\n%d %d\n255\n", image_width, image_height);
	while (j >= 0)
	{
		while (i < image_width)
		{
			double r = (double)i / (image_width - 1);
			double g = (double)j / (image_height - 1);
			double b = 0.25;

			int ir = (int)(255.999 * r);
			int ig = (int)(255.999 * g);
			int ib = (int)(255.999 * b);

			printf("%d %d %d\n", ir, ig, ib);
			++i;
		}
		--j;
	}
	return (0);
}
