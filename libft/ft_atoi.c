/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:38:49 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/20 18:38:50 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t				i;
	int					negative;
	unsigned long int	nmb;

	i = 0;
	negative = 1;
	nmb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		nmb = (nmb * 10) + (str[i] - '0');
		if (nmb >= 922337203685477580 && negative == 1)
			return (-1);
		else if (nmb > 922337203685477580 && negative == -1)
			return (0);
		i++;
	}
	return ((int)(nmb * negative));
}
