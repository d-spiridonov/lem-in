/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:09:41 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/13 20:09:42 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	unsigned char	*stmp1;
	unsigned char	*stmp2;

	if (s1 != NULL && s2 != NULL)
	{
		stmp1 = (unsigned char*)s1;
		stmp2 = (unsigned char*)s2;
		while (*stmp1 != '\0' || *stmp2 != '\0')
		{
			if (*stmp1 < *stmp2 || *stmp1 > *stmp2)
				return (0);
			stmp1++;
			stmp2++;
		}
		return (1);
	}
	return (0);
}
