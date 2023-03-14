/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:08:31 by esimsek           #+#    #+#             */
/*   Updated: 2022/02/08 13:43:49 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*iter;

	iter = lst;
	i = 0;
	while (iter != NULL)
	{
		iter = iter -> next;
		i++;
	}
	return (i);
}

/*
void	ekle(t_list	*iter, char *str)
{
	while (iter -> next != NULL)
		iter = iter -> next;
	iter -> next = (t_list *)malloc(sizeof(t_list));
	iter -> next -> content = str;
	iter -> next -> next = NULL;
}

int	main()
{
	t_list	*lst;
	int		i;
	
	lst = (t_list *)malloc(sizeof(t_list));
	lst -> next = NULL;
	lst -> content = "Merhaba ";
	i = 0;
	ekle(lst, "Emre");
	ekle(lst, " Naber kankss");

	i = ft_lstsize(lst);
	printf("boyutu: %d\nicerik: %s%s%s", i, lst -> content,);
	content, lst -> next -> next -> content);
}
*/