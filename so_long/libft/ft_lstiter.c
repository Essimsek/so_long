/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:32:42 by esimsek           #+#    #+#             */
/*   Updated: 2022/02/08 16:37:05 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Listenin üzerinde dolanır ve ‘f’ fonksiyonunu
listenin her elemanının içeriğine uygular.
*/
//void	f(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*iter;

	if (!lst || !f)
		return ;
	iter = lst;
	while (iter != NULL)
	{
		f(iter -> content);
		iter = iter -> next;
	}
}
/*
void	f(void *content)
{
	printf("%s\n", content);
}

int	main()
{
	t_list	*lst;

	lst = ft_lstnew("ilk");
	lst -> next = ft_lstnew("ikinci");
	lst -> next -> next = ft_lstnew("ucuncu");
	ft_lstiter(lst, f);
}
*/