/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 20:17:24 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/14 20:17:47 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_modifier_o(va_list args, t_p *pf)
{
	if (pf->size_m == 0)
		return (va_arg(args, unsigned int));
	else if (pf->size_m == 2)
		return (unsigned short)(va_arg(args, int));
	else if (pf->size_m == 1)
		return (unsigned char)(va_arg(args, int));
	else if (pf->size_m == 3)
		return (va_arg(args, unsigned long));
	else if (pf->size_m == 4)
		return (va_arg(args, unsigned long long));
	else if (pf->size_m == 5)
		return (va_arg(args, uintmax_t));
	else if (pf->size_m == 6)
		return (va_arg(args, size_t));
	return (0);
}

long long			ft_modifier_d(va_list args, t_p *pf)
{
	if (pf->size_m == 0)
		return (va_arg(args, int));
	else if (pf->size_m == 2)
		return (short)(va_arg(args, int));
	else if (pf->size_m == 1)
		return (char)(va_arg(args, int));
	else if (pf->size_m == 3)
		return (va_arg(args, long));
	else if (pf->size_m == 4 || pf->size_m == 10)
		return (va_arg(args, long long));
	else if (pf->size_m > 4)
		return (va_arg(args, intmax_t));
	else if (pf->size_m == 6)
		return (va_arg(args, size_t));
	return (-1);
}
