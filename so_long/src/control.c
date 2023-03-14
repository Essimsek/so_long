/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerensimsek <cerensimsek@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:37:49 by cerensimsek       #+#    #+#             */
/*   Updated: 2023/01/27 23:03:09 by cerensimsek      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_undefined_char(t_data *data)
{
	int			i;
	int			j;
	char		*defined_chars;

	defined_chars = malloc(sizeof(char) * 5);
	defined_chars = "01PEC";
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!ft_strchr(defined_chars, data->map[i][j]))
				map_errors(UNDEFINED_CHAR);
			j++;
		}
		i++;
	}
}

int	is_the_map_type_correct(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len <= 4)
	{
		ft_printf("Map type error!!\n");
		exit (0);
	}
	if (path[len - 1] == 'r' && path[len - 2] == 'e'\
	&& path[len - 3] == 'b' && path[len - 4] == '.' && \
	path[len - 5] != '/')
		return (1);
	ft_printf("Map type error!!\n");
	exit (0);
}

// checks if mlx initilazed correctly
void	mlx_control(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_printf("Error!\nmlx dude!! mlx is not initialized correctly");
		exit(0);
	}
	ft_printf("mlx is initialized!\n");
}
