/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jelvan-d <jelvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/26 11:43:09 by jelvan-d      #+#    #+#                 */
/*   Updated: 2020/07/06 17:26:57 by jelvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*to fix:
	-- Free 2d array and strjoin if error
*/

int	invertcolor(int	trgb)
{
	
}

int	close_window(int keycode, t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
}

int	main(void)
{
	t_data	img;
	int i = 0, j = 0;
	
	parser();
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1280, 720, "Cub3d");
	img.img = mlx_new_image(img.mlx, 1280, 720);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i < 426)
	{
		j = 0;
		while (j < 720)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
	while (i < 853)
	{
		j = 0;
		while (j < 720)
		{
			my_mlx_pixel_put(&img, i, j, invertcolor(0x00FFFFFF));
			j++;
		}
		i++;
	}
	while (i < 1280)
	{
		j = 0;
		while (j < 720)
		{
			my_mlx_pixel_put(&img, i, j, 0x000F1DD9);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_key_hook(img.mlx_win, close_window, &img);
	mlx_loop(img.mlx);
	return (0);
}
