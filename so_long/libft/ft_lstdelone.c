/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:46:09 by esimsek           #+#    #+#             */
/*   Updated: 2022/02/08 18:32:01 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
// void del(void *str)
// {
// 	free(str);
// }

// int main ()
// {
// 	t_list *list;
// 	t_list *next;
// 	list = ft_lstnew(ft_strdup("hello"));
// 	ft_lstadd_back(&list, ft_lstnew(ft_strdup("world")));
// 	next = list->next;
// 	ft_lstdelone(list,del);
// 	printf("%s",(char *)list -> content);
// }