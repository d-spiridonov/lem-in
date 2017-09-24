/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 20:02:20 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/14 20:06:18 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nulintend_d(long long int nmb, t_p *pf)
{
	size_t	count;

	count = 0;
	if (nmb < 0)
		ft_putchar_pf('-', pf);
	if (pf->fldwt > (ft_countdigits(nmb) + pf->space + \
	pf->plus))
		while (count++ < (pf->fldwt - (ft_countdigits(nmb) + pf->space + \
		pf->plus)))
			ft_putchar_pf('0', pf);
	pf->plus = 0;
}

void	indent_o(long long int nmb, t_p *pf)
{
	size_t	count;
	size_t	diff;
	size_t	itoa;
	int		dotzero;

	diff = 0;
	dotzero = (pf->dot == 1 && nmb == 0 && pf->prec == 0) ? 1 : 0;
	itoa = ft_strlen(pf->fstr);
	if ((pf->min > 0 || pf->dot == 1) && (pf->sp == 9 || pf->sp == 10 ||
			(pf->prec > itoa && pf->sp == 7)))
		pf->hash = 0;
	if (pf->prec > 0 && pf->prec > itoa)
		diff = (pf->prec - itoa);
	count = 0;
	if (pf->fldwt > (itoa + diff))
		while (count++ < (pf->fldwt - (itoa + diff + pf->hash) + dotzero))
			ft_putchar_pf(' ', pf);
}

void	indent_d(long long int nmb, t_p *pf)
{
	size_t	count;
	int		diff;
	int		dotzero;

	diff = pf->prec - ft_countdigits(nmb);
	dotzero = (pf->dot == 1 && nmb == 0 && pf->prec == 0) ? 1 : 0;
	if (diff < 0)
		diff = 0;
	if (nmb < 0 && pf->prec > (size_t)ft_countdigits(nmb))
		diff++;
	count = (pf->prec == (size_t)ft_countdigits(nmb) && nmb < 0) ? 1 : 0;
	if (pf->fldwt > (size_t)ft_countdigits(nmb) + pf->space + pf->plus + \
		diff - dotzero)
		while ((size_t)count++ < (pf->fldwt - (ft_countdigits(nmb) +\
		pf->space + pf->plus + diff - dotzero)))
			ft_putchar_pf(' ', pf);
}

void	ft_precision_d(long long int *val, t_p *pf)
{
	int	diff;

	diff = pf->prec - ft_countdigits(*val);
	if (*val < 0)
		diff++;
	if (pf->plus == 1)
	{
		ft_putchar_pf('+', pf);
		pf->fldwt--;
	}
	if (*val < 0)
		ft_putchar_pf('-', pf);
	pf->plus = 0;
	while (diff-- > 0)
		ft_putchar_pf('0', pf);
}

void	zero_pf(t_p *pf)
{
	pf->min = 0;
	pf->plus = 0;
	pf->space = 0;
	pf->hash = 0;
	pf->nulchr = 0;
	pf->size_m = 0;
	pf->prec = 0;
	pf->fldwt = 0;
	pf->sp = 0;
	pf->dot = 0;
}
