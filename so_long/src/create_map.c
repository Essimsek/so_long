/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerensimsek <cerensimsek@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:49:57 by esimsek           #+#    #+#             */
/*   Updated: 2023/01/27 22:58:01 by cerensimsek      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks if file is exist.
static int	check_is_there_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error!\nFile is not exist!\n");
		exit(0);
	}
	else
		ft_printf("File have founded\n");
	return (fd);
}

// Checks if the file empty or not
static void	check_is_file_empty(char *file, int fd)
{
	if (!file)
	{
		ft_printf("Error!!\nFile is empty!!");
		close(fd);
		exit (1);
	}
}

// Checks if the walls setted correctly
static void	check_walls(t_data *data, char *read)
{
	int				i;
	size_t			j;
	size_t			width;

	data->map = ft_split(read, '\n');
	width = ft_strlen(data->map[0]);
	i = -1;
	while (data->map[++i])
		if (ft_strlen(data->map[i]) != width)
			map_errors(WIDTH_ERROR);
	i = -1;
	while (data->map[++i])
		if (data->map[i][0] != '1' || data->map[i][width - 1] != '1')
			map_errors(NOT_SURROUNDED);
	j = -1;
	while (++j < width)
		if (data->map[0][j] != '1' || data->map[i - 1][j] != '1')
			map_errors(NOT_SURROUNDED);
	data->map_obj.map_y = i - 1;
	data->map_obj.map_x = width;
}

// This function counts all the map components
static void	check_number_of_characters(char *map, t_data *data)
{
	int	i;

	data->map_obj.c_player = 0;
	data->map_obj.c_exit = 0;
	data->map_obj.c_collectable = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			data->map_obj.c_player += 1;
		else if (map[i] == 'E')
			data->map_obj.c_exit += 1;
		else if (map[i] == 'C')
			data->map_obj.c_collectable += 1;
		i++;
	}
	if (data->map_obj.c_player != 1 || \
		data->map_obj.c_exit != 1 || \
		data->map_obj.c_collectable < 1)
		map_errors(MAP_COMPONENTS);
}

// this function will read the file and set data->map as a map
void	create_map(char *file, t_data *data)
{
	int		fd;
	char	*tmp;
	char	*read;
	char	*buffer;

	fd = check_is_there_file(file);
	tmp = get_next_line(fd);
	check_is_file_empty(tmp, fd);
	read = NULL;
	buffer = ft_calloc(sizeof(char *), 1);
	while (tmp)
	{
		read = ft_strjoin(buffer, tmp);
		free(buffer);
		free(tmp);
		buffer = read;
		tmp = get_next_line(fd);
	}
	check_walls(data, read);
	check_number_of_characters(read, data);
	check_undefined_char(data);
	free(read);
	close(fd);
}
