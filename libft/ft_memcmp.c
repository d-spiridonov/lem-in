/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:46:43 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/06 16:47:41 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*stmp1;
	unsigned char	*stmp2;
	unsigned int	i;
	int				count;

	stmp1 = (unsigned char*)s1;
	stmp2 = (unsigned char*)s2;
	count = 0;
	i = 0;
	while (i != n)
	{
		if (*stmp1 < *stmp2 || *stmp1 > *stmp2)
		{
			count = *stmp1 - *stmp2;
			return (count);
		}
		stmp1++;
		stmp2++;
		i++;
	}
	return (0);
}
