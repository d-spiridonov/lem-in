/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:14:35 by dspyrydo          #+#    #+#             */
/*   Updated: 2016/12/18 14:14:37 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tmp;
	char			c;

	tmp = n < 0 ? -n : n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (tmp > 9)
	{
		ft_putnbr_fd(tmp / 10, fd);
		ft_putnbr_fd(tmp % 10, fd);
	}
	else
	{
		c = tmp + '0';
		ft_putchar_fd(c, fd);
	}
}
