/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerensimsek <cerensimsek@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:50:08 by esimsek           #+#    #+#             */
/*   Updated: 2023/01/27 23:08:58 by cerensimsek      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// simple error handle function
void	map_errors(int error)
{
	if (error == WIDTH_ERROR)
	{
		ft_printf("Map width must be the same each row!!!\n");
		exit (1);
	}
	else if (error == NOT_SURROUNDED)
	{
		ft_printf("Map must be surrounded by 1\n");
		exit (1);
	}
	else if (error == MAP_COMPONENTS)
	{
		ft_printf("The map should consist of one 'E', one 'P' ");
		ft_printf("and at least one 'C'");
		exit (1);
	}
	else if (error == NOT_VALID)
	{
		ft_printf("Error!! Your map is not valid..\n");
		exit(1);
	}
	else if (error == UNDEFINED_CHAR)
	{	
		ft_printf("Error!! Your map has an undefined char..\n");
		exit(1);
	}
}
