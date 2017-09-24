/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 20:13:16 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/14 20:14:07 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flagparser(const char *format, int i)
{
	if (format[i] == 'h')
		while (ft_strchr("sSpdDioOuUxXcC", format[++i]) == NULL && format[i])
		{
			if (format[i] == 'h')
				return (1);
		}
	else
		while (ft_strchr("sSpdDioOuUxXcC", format[++i]) == NULL && format[i])
		{
			if (format[i] == 'l')
				return (1);
		}
	return (0);
}

void	put0x(t_p *pf)
{
	ft_putchar_pf('0', pf);
	ft_putchar_pf('x', pf);
}
