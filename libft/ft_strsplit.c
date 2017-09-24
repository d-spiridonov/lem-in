/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:58:16 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/15 10:58:18 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	char	**dst;
	size_t	iw;
	size_t	wb;
	size_t	i;

	if (s != NULL && c)
	{
		i = 0;
		iw = 0;
		if (!(dst = (char **)malloc(sizeof(char*) * (ft_countwords(s, c) + 1))))
			return (NULL);
		while (iw < ft_countwords(s, c))
		{
			while (s[i] == c)
				i++;
			wb = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			if ((i - wb) != 0)
				dst[iw++] = ft_strsub(s, wb, (i - wb));
		}
		dst[iw] = NULL;
		return (dst);
	}
	return (NULL);
}
