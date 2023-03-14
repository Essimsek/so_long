/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:28:04 by aerincik          #+#    #+#             */
/*   Updated: 2022/02/08 14:35:57 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// new in nextine lst yi göstermesi
// için işaret ediyorum daha sonrada
// lst nin newi göstermesini sağlıyorum
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int main()
{
	t_list *list;
	t_list *eklenecek;

	list = malloc(sizeof(t_list));
	eklenecek = malloc(sizeof(t_list));
	eklenecek->content = "as";
	list->content = "sa";
	list ->next = NULL;
	ft_lstadd_front(&list, eklenecek);
	printf("%s\n%s",(char *)list->content, (char *)list -> next -> content);
}
*/