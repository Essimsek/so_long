/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:17:56 by cerensimsek       #+#    #+#             */
/*   Updated: 2022/02/08 13:43:48 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// hafızadan yer ayırıp sonra yeni eleman çıktı olarak verilir
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}
/*
int	main()
{
	char	*str = "Naber kanksss";
	t_list	*r;

	r = ft_lstnew(str);
	printf("%s", (char *)r -> content);
}
*/