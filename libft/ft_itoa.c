/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:52:11 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/17 16:52:13 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*dst;
	size_t			count;
	int				negative;
	unsigned int	t;

	negative = 0;
	count = ft_countdigits(n);
	if (n < 0)
	{
		negative = 1;
		n = n * -1;
	}
	t = n;
	if (!(dst = ft_strnew(count + negative)))
		return (NULL);
	while (count > 0)
	{
		count--;
		dst[count + negative] = t % 10 + 48;
		t = t / 10;
	}
	if (negative == 1)
		dst[0] = 45;
	return (dst);
}
