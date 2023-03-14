/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerensimsek <cerensimsek@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:49:32 by esimsek           #+#    #+#             */
/*   Updated: 2023/01/28 01:19:38 by cerensimsek      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"

enum {
	LEFT = 123,
	RIGHT = 124,
	DOWN = 125,
	UP = 126
};

enum {
	WIDTH_ERROR,
	NOT_SURROUNDED,
	MAP_COMPONENTS,
	NOT_VALID,
	UNDEFINED_CHAR
};

// c = count
typedef struct s_map
{
	int		c_exit;
	int		c_collectable;
	int		c_player;
	int		p_x;
	int		p_y;
	int		map_y;
	int		map_x;
}					t_map;

typedef struct s_images
{
	void	*floor_img;
	void	*wall_img;
	void	*pl_fimg;
	void	*pl_bimg;
	void	*pl_limg;
	void	*pl_rimg;
	void	*d_cimg;
	void	*d_oimg;
	void	*cl_bhlt;
}					t_images;

typedef struct s_data
{
	char		**map;
	char		**copied_map;
	void		*win;
	void		*mlx;
	int			wdht;
	int			hght;
	int			curr;
	int			key;
	int			step_count;
	t_map		map_obj;
	t_images	*imgs;
}					t_data;

void		mlx_control(t_data *data);
void		create_map(char *file, t_data *data);
void		map_errors(int error);
void		find_player_position(t_data *data);
void		is_the_path_valid(t_data *data);
void		fill(int x, int y, t_data *data);
void		check_is_there_any_collectable_left(t_data *data);
void		check_undefined_char(t_data *data);
void		get_images(t_images *imgs, t_data *data);
void		set_imgs(t_images *imgs, t_data *data);
void		put_imgs(t_images *imgs, t_data *data, int x, int y);
void		check_exit(int key, t_data *data);
int			is_the_map_type_correct(char *path);
int			close_win(t_data *data);

#endif