/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:32:27 by esimsek           #+#    #+#             */
/*   Updated: 2022/02/08 13:44:10 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
// verdiğin başlangıç değerinden verdiğin size a kadar olan stringi döndürür
#include<stdio.h>
int	main()
{
	char const *s = "e na.ber";
	unsigned int	i = 4;
	size_t	len = 5;
	char	*test;

	test = ft_substr(s, i, len);	
	printf("%s\n%zu", test, ft_strlen(test));
}
*/