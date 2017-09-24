/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 19:58:06 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/14 19:58:47 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	indent_c(t_p *pf)
{
	size_t count;

	count = 0;
	while (count++ < (pf->fldwt - 1))
		ft_putchar_pf(' ', pf);
}

void	indent_s(char *str, t_p *pf)
{
	size_t count;
	size_t diff;

	diff = ft_strlen(str);
	count = 0;
	if (pf->dot > 0 && pf->prec < diff && pf->fldwt > pf->prec)
		while (count++ < (pf->fldwt - pf->prec))
			ft_putchar_pf(' ', pf);
	else if (pf->prec > 0 && pf->fldwt > diff)
		while (count++ < (pf->fldwt - diff))
			ft_putchar_pf(' ', pf);
	else if (pf->prec == 0)
		while (count++ < (pf->fldwt - diff) && pf->fldwt > diff)
			ft_putchar_pf(' ', pf);
}

void	ft_zerobefore(long long int val, t_p *pf)
{
	if (val == 0 && (pf->dot == 0))
	{
		if (pf->sp == 3)
			put0x(pf);
	}
	else
	{
		if ((pf->sp == 9 || pf->sp == 8) && pf->dot == 0)
			ft_putchar_pf('0', pf);
		if (pf->sp == 7 && val != 0)
			ft_putchar_pf('0', pf);
		if (pf->sp == 11 && ((pf->dot == 0 || pf->prec > 0) || \
				(pf->dot == 1 && val != 0)))
			put0x(pf);
		if (pf->sp == 3)
			put0x(pf);
		if (pf->sp == 12)
		{
			ft_putchar_pf('0', pf);
			ft_putchar_pf('X', pf);
		}
	}
	if ((pf->min > 0 || pf->dot == 1) && (pf->sp == 9 || pf->sp == 10 || \
	(pf->sp == 7 && val == 0)))
		pf->hash = 0;
}

void	ft_precision_s(char *str, t_p *pf)
{
	size_t i;

	i = 0;
	if (str != NULL)
		while (i < pf->prec && str[i] != '\0')
			ft_putchar_pf(str[i++], pf);
}

void	nulintend_c(t_p *pf)
{
	size_t	count;

	count = 0;
	if (pf->fldwt > (1 + pf->space + pf->plus))
	{
		while (count++ < (pf->fldwt - (1 + pf->space + \
		pf->plus)))
			ft_putchar_pf('0', pf);
		pf->plus = 0;
	}
}
