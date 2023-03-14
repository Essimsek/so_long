/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:40:07 by esimsek           #+#    #+#             */
/*   Updated: 2022/02/08 17:47:53 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//tmp son elemanı tutar
//sonra son elemanın nextine new i ekler
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp -> next = new;
}
/*
int	main()
{
	t_list *lst;
	t_list *eklenecek;
	t_list	*iter;
	int		x;
	int		i;
	char	str[100];
	int index = 1;


	i = 0;
	eklenecek = malloc(sizeof(t_list));
	eklenecek->content = "son";
	
	printf("Kac elemanli: ");
	scanf("%d", &x);
	while (i < x)
	{
		printf("Kelime: ");
		scanf("%s", str);
		if (i == 0)
		{
			lst =(t_list *)malloc(sizeof(t_list));
			lst -> content = ft_strdup(str);
			iter = lst;
		}	
		else
		{	
			iter -> next= malloc(sizeof(t_list));
			iter = iter -> next; 
			iter -> content = ft_strdup(str); 
			iter -> next = NULL;
		}
		i++;
	}
	ft_lstadd_back(&lst, eklenecek);
	iter = lst;
	printf("tum liste\n");
	while (iter != NULL)
	{
		printf("%d. \"%s\"\n", index++, iter->content);
		iter = iter->next;
	}
}
*/