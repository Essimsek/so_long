/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:25:56 by esimsek           #+#    #+#             */
/*   Updated: 2022/02/08 13:44:08 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = ft_strlen(s);
	ptr = 0;
	while (i > 0 && (char)s[i] != (char)c)
	{
		if ((char)s[i] == (char)c)
			ptr = (char *)(s + i);
		i--;
	}
	if ((char)s[i] == (char)c)
		ptr = (char *)(s + i);
	return (ptr);
}
/*
gördüğü verdiğimiz karaktere eşit ise
int	main()
{
	char s[] = "some, data, inco/ ,  /mmas ";
	char *deneme = ft_strrchr(s, ',');
	printf("%s", deneme);
}
*/