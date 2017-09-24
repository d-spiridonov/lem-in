/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 21:22:32 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/13 21:22:34 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		if (!(dst = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2))))
			return (NULL);
		while (*s1)
		{
			dst[i] = (char)*s1;
			i++;
			s1++;
		}
		while (*s2)
		{
			dst[i] = (char)*s2;
			i++;
			s2++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
