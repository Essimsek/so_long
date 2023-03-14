/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:38:22 by esimsek           #+#    #+#             */
/*   Updated: 2022/02/10 19:27:13 by esimsek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	return_lenght(const char *str, char c)
{
	int	i;
	int	control;

	i = 0;
	control = 0;
	while (*str)
	{
		if (*str != c && control == 0)
		{
			control = 1;
			i++;
		}
		else if (*str == c)
			control = 0;
		str++;
	}
	return (i);
}

static char	*add_words(const char *str, int origin, int c)
{
	size_t	i;
	char	*sw;

	if (!str)
		return (NULL);
	sw = (char *)malloc((c + 1) * sizeof(char));
	i = 0;
	while ((size_t)origin < ft_strlen(str) && i < (size_t)c)
	{
		sw[i++] = str[origin++];
	}
	sw[i] = '\0';
	return (sw);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**sp;

	sp = malloc((return_lenght(s, c) + 1) * sizeof(char *));
	if (!sp || !s)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && (index >= 0))
		{
			sp[j++] = add_words(s, index, i - index);
			index = -1;
		}
		i++;
	}
	sp[j] = 0;
	return (sp);
}
/* 
#include<stdio.h>
int main ()
{
	char **str = ft_split("  tripouille 42  ", ' ');
	//originden c ye kadar olan stringimi tutacak olan char pointer pointeri..	
	//i - index fazladan alan açmamak için yapılan işlem
	printf("%zu\n", ft_strlen(str[0]));
	system("leaks a.out");
}
 */