/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:30:57 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/13 20:30:59 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	*stmp1;
	unsigned char	*stmp2;
	size_t			i;

	if (s1 != NULL && s2 != NULL)
	{
		stmp1 = (unsigned char*)s1;
		stmp2 = (unsigned char*)s2;
		i = 0;
		while (i < n && (*stmp1 || *stmp2))
		{
			if (*stmp1 < *stmp2 || *stmp1 > *stmp2)
				return (0);
			stmp1++;
			stmp2++;
			i++;
		}
		return (1);
	}
	return (0);
}
