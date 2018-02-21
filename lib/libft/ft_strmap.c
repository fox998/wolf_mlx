/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:48:06 by afokin            #+#    #+#             */
/*   Updated: 2017/10/30 15:48:10 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		lens;
	int		i;
	char	*ptr;
	char	*iptr;
	char	c;

	if (s == 0)
		return (0);
	lens = ft_strlen((char *)s);
	i = 0;
	if (!(ptr = malloc(lens + 1)))
		return (0);
	iptr = ptr;
	while (s[i])
	{
		if ((c = f(s[i])))
		{
			*iptr = c;
			iptr++;
		}
		i++;
	}
	*iptr = 0;
	return (ptr);
}
