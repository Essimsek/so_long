/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerensimsek <cerensimsek@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 01:16:51 by cerensimsek       #+#    #+#             */
/*   Updated: 2023/01/27 23:06:05 by cerensimsek      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_imgs(t_data *data)
{
	free(data->imgs->cl_bhlt);
	free(data->imgs->pl_bimg);
	free(data->imgs->pl_fimg);
	free(data->imgs->pl_limg);
	free(data->imgs->pl_rimg);
	free(data->imgs->floor_img);
	free(data->imgs->wall_img);
	free(data->imgs->d_cimg);
	free(data->imgs->d_oimg);
	exit(1);
}

int	close_win(t_data *data)
{
	(void)data;
	exit(1);
}

void	check_exit(int key, t_data *data)
{
	int	x;
	int	y;

	x = data->map_obj.p_x;
	y = data->map_obj.p_y;
	if (data->map_obj.c_collectable == 0)
	{
		if (key == RIGHT && data->map[y][x + 1] == 'E')
			exit(1);
		if (key == LEFT && data->map[y][x - 1] == 'E')
			exit(1);
		if (key == DOWN && data->map[y + 1][x] == 'E')
			exit(1);
		if (key == UP && data->map[y - 1][x] == 'E')
			exit(1);
	}
}
