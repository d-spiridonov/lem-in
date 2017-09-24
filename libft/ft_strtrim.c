/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:00:51 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/14 13:00:53 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dst;
	size_t	i;
	size_t	i2;
	size_t	i3;

	if (s != NULL)
	{
		i3 = 0;
		i2 = ft_strlen((char*)s) - 1;
		i = 0;
		while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
			i++;
		while ((s[i2] == '\t' || s[i2] == '\n' || s[i2] == ' ') && i2 > i)
			i2--;
		if (!(dst = ft_strnew(i2 - i + 1)))
			return (NULL);
		while (i < (i2 + 1))
			dst[i3++] = s[i++];
		dst[i3] = '\0';
		return (dst);
	}
	return (NULL);
}
