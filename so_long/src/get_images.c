/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerensimsek <cerensimsek@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:12:55 by cerensimsek       #+#    #+#             */
/*   Updated: 2023/01/26 18:38:11 by cerensimsek      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images(t_images *imgs, t_data *data)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	mlx_control(data);
	data->hght = 64 * (data->map_obj.map_y + 1);
	data->wdht = 64 * data->map_obj.map_x;
	data->win = mlx_new_window(data->mlx, data->wdht, data->hght, "So_Long");
	imgs->wall_img = mlx_xpm_file_to_image(data->mlx, "./asts/wll.xpm", &x, &y);
	imgs->d_cimg = mlx_xpm_file_to_image(data->mlx, "./asts/cdoor.xpm", &x, &y);
	imgs->d_oimg = mlx_xpm_file_to_image(data->mlx, "./asts/odoor.xpm", &x, &y);
	imgs->floor_img = mlx_xpm_file_to_image(data->mlx, "./asts/fl.xpm", &x, &y);
	imgs->pl_fimg = mlx_xpm_file_to_image(data->mlx, "./asts/plfr.xpm", &x, &y);
	imgs->pl_bimg = mlx_xpm_file_to_image(data->mlx, "./asts/plbc.xpm", &x, &y);
	imgs->pl_rimg = mlx_xpm_file_to_image(data->mlx, "./asts/plrt.xpm", &x, &y);
	imgs->pl_limg = mlx_xpm_file_to_image(data->mlx, "./asts/plft.xpm", &x, &y);
	imgs->cl_bhlt = mlx_xpm_file_to_image(data->mlx, "./asts/coll.xpm", &x, &y);
	data->key = 0;
}

void	set_imgs(t_images *imgs, t_data *data)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	pos;

	i = 0;
	y = 0;
	while (i <= data->map_obj.map_y)
	{
		j = 0;
		x = 0;
		while (j < data->map_obj.map_x)
		{
			pos = data->map[i][j];
			data->curr = pos;
			put_imgs(imgs, data, x, y);
			j += 1;
			x += 64;
		}
		y += 64;
		i += 1;
	}
}

void	put_imgs(t_images *imgs, t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, imgs->floor_img, x, y);
	if (data->curr == '1')
		mlx_put_image_to_window(data->mlx, data->win, imgs->wall_img, x + 2, y);
	if (data->curr == 'C')
		mlx_put_image_to_window(data->mlx, data->win, imgs->cl_bhlt,
			x + 16, y + 16);
	if (data->curr == 'E')
	{
		if (data->map_obj.c_collectable == 0)
			mlx_put_image_to_window(data->mlx, data->win, imgs->d_oimg, x, y);
		else
			mlx_put_image_to_window(data->mlx, data->win, imgs->d_cimg, x, y);
	}
	if (data->curr == 'P')
	{
		if (data->key == LEFT)
			mlx_put_image_to_window(data->mlx, data->win, imgs->pl_limg, x, y);
		if (data->key == RIGHT)
			mlx_put_image_to_window(data->mlx, data->win, imgs->pl_rimg, x, y);
		if (data->key == DOWN || data->key == 0)
			mlx_put_image_to_window(data->mlx, data->win, imgs->pl_fimg, x, y);
		if (data->key == UP)
			mlx_put_image_to_window(data->mlx, data->win, imgs->pl_bimg, x, y);
	}
}
