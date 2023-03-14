/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerensimsek <cerensimsek@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:21:40 by esimsek           #+#    #+#             */
/*   Updated: 2023/01/25 17:06:19 by cerensimsek      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	find_player_position(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->map_obj.p_x = j;
				data->map_obj.p_y = i;
			}
			j++;
		}
		i++;
	}
}

void	is_the_path_valid(t_data *data)
{
	int	i;

	i = 0;
	find_player_position(data);
	data->copied_map = malloc(sizeof(char *) * (data->map_obj.map_y + 1));
	while (data->map[i])
	{
		data->copied_map[i] = ft_strdup(data->map[i]);
		i++;
	}
	fill(data->map_obj.p_x, data->map_obj.p_y, data);
	check_is_there_any_collectable_left(data);
}

void	fill(int x, int y, t_data *data)
{
	char	curr;

	curr = data->copied_map[y][x];
	if (curr == '1' || curr == 'x')
		return ;
	if (curr == 'E')
	{
		data->copied_map[y][x] = 'x';
		return ;
	}	
	data->copied_map[y][x] = 'x';
	fill(x, y - 1, data);
	fill(x, y + 1, data);
	fill(x + 1, y, data);
	fill(x - 1, y, data);
}

void	check_is_there_any_collectable_left(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i <= data->map_obj.map_y)
	{
		j = -1;
		while (data->copied_map[i][++j])
		{
			if (data->copied_map[i][j] == 'C')
				map_errors(NOT_VALID);
			else if (data->copied_map[i][j] == 'E')
				map_errors(NOT_VALID);
			ft_printf("%c", data->copied_map[i][j]);
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("Your map is valid man\n");
}
