/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:55:53 by esimsek           #+#    #+#             */
/*   Updated: 2022/02/08 19:20:43 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// del ve free kullanarak bütün elemanları
// hafızadan siler
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
// void	del(char *str)
// {
// 	free(str);
// }

// void	a(char *str)
// {
// 	printf("%s", str);
// }

// int	main()
// {
// 	t_list	*list;

// 	list = ft_lstnew(ft_strdup("SA\n"));
// 	ft_lstadd_back(&list, ft_lstnew(ft_strdup("merhaba\n")));
// 	ft_lstadd_back(&list, ft_lstnew(ft_strdup("dunya\n")));
// 	ft_lstadd_back(&list, ft_lstnew(ft_strdup("!\n")));
// 	ft_lstiter(list, (void *)a);
// 	ft_lstclear(&list, (void *)del);
// 	printf("%s", (char *)list -> content);
// }