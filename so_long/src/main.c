/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerensimsek <cerensimsek@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:49:53 by esimsek           #+#    #+#             */
/*   Updated: 2023/01/28 01:21:08 by cerensimsek      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	play_sound(void)
{
	system("canberra-gtk-play -f ./music/game_music.wav");
}

static void	update_player_pos(int key, t_data *data)
{
	int	x;
	int	y;

	x = data->map_obj.p_x;
	y = data->map_obj.p_y;
	data->map[data->map_obj.p_y][data->map_obj.p_x] = '0';
	if (key == RIGHT && data->map[y][x + 1] != 'E')
		data->map_obj.p_x += 1;
	if (key == LEFT && data->map[y][x - 1] != 'E')
		data->map_obj.p_x -= 1;
	if (key == DOWN && data->map[y + 1][x] != 'E')
		data->map_obj.p_y += 1;
	if (key == UP && data->map[y - 1][x] != 'E')
		data->map_obj.p_y -= 1;
	if (data->map[data->map_obj.p_y][data->map_obj.p_x] == 'C')
		data->map_obj.c_collectable -= 1;
	data->map[data->map_obj.p_y][data->map_obj.p_x] = 'P';
}

static int	check_wall(int k, t_data *data)
{
	int	x;
	int	y;

	x = data->map_obj.p_x;
	y = data->map_obj.p_y;
	if (k == RIGHT && data->map[y][x + 1] != '1')
		return (1);
	if (k == LEFT && data->map[y][x - 1] != '1')
		return (1);
	if (k == DOWN && data->map[y + 1][x] != '1')
		return (1);
	if (k == UP && data->map[y - 1][x] != '1')
		return (1);
	return (0);
}

static int	gameplay(int k, t_data *data)
{
	data->key = k;
	if (k == 53)
		exit (1);
	if (k == RIGHT || k == LEFT || k == DOWN || k == UP)
	{
		if (check_wall(k, data))
		{
			check_exit(k, data);
			update_player_pos(k, data);
			data->step_count += 1;
			ft_printf("Step count: %d\n", data->step_count);
		}
		mlx_clear_window(data->mlx, data->win);
		set_imgs(data->imgs, data);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2)
		return (1);
	data = ft_calloc(sizeof(t_data), 1);
	data->imgs = ft_calloc(sizeof(t_images), 1);
	data->key = 0;
	data->step_count = 0;
	if (!data)
		exit(1);
	if (is_the_map_type_correct(argv[1]))
		create_map(argv[1], data);
	is_the_path_valid(data);
	get_images(data->imgs, data);
	play_sound();
	set_imgs(data->imgs, data);
	mlx_hook(data->win, 2, 0, gameplay, data);
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_loop(data->mlx);
	return (0);
}
	// 123 <-
	// 124 ->
	// 126 ^
	// 125 down
	//system("leaks so_long");
	// Update hooku, her kare calisacak bir fonksyon
	//mlx_loop_hook(vars.mlx, update, &vars);
	// https://www.youtube.com/watch?v=BAahPJS-G4c LERP icin
	// curr_pos = lerp(curr_pos, target_pos, 0.2);
