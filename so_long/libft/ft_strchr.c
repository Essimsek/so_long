/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:00:32 by esimsek           #+#    #+#             */
/*   Updated: 2022/02/08 13:43:59 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == c)
		return (&str[i]);
	return (0);
}
/*
int	main ()
{
	char	emre[20];
	char	a;
	char	*sonuc;
	printf("lutfen bir cumle giriniz: ");
	gets(emre);
//	printf("Hangi karakterden itibaren istiyorsun: ");
//	scanf("%c",&a);
	sonuc = ft_strchr(emre, 'a'); // 97 girsen gene a
	printf("%s", sonuc);
}
*/
