/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:16:46 by esimsek           #+#    #+#             */
/*   Updated: 2022/02/10 13:05:50 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// sondaki bağlı listeye gider
// ve onu döndürür..
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*iter;

	if (!lst)
		return (0);
	iter = lst;
	while (iter -> next != NULL)
		iter = iter -> next;
	return (iter);
}
/*
int	main()
{
	t_list	*lst;
	t_list	*iter;
	char	str[100];
	int		x;
	int		i;

	i = 0;
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
	iter = lst;
	int index = 1;
	printf("tum liste\n");
	while (iter != NULL)
	{
		printf("%d. \"%s\"\n", index++, iter->content);
		iter = iter->next;
	}
	printf("\t--Son eleman--\n");
	printf("The last: %s", (char *)ft_lstlast(lst) -> content);
}

bi tane liste olştr.
2 linked listi birbirine bağla...
sonra bağlanmış olan listeyi yeni listenin en başına koy

*/
