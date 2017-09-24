/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 20:07:21 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/14 20:10:51 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nulintend_o(t_p *pf)
{
	unsigned long	count;
	size_t			itoa;

	itoa = ft_strlen(pf->fstr);
	count = 0;
	if (pf->fldwt > itoa)
		while (count++ < (pf->fldwt - itoa))
			ft_putchar_pf('0', pf);
	pf->plus = 0;
	pf->nulchr = 0;
}

void	ft_precision_o(long long int val, t_p *pf)
{
	size_t	diff;

	diff = 0;
	if (val >= 0 && pf->prec > ft_strlen(pf->fstr))
		diff = pf->prec - (ft_strlen(pf->fstr)) - pf->hash;
	while (diff-- > 0)
		ft_putchar_pf('0', pf);
}

void	indent_x(long long int nmb, t_p *pf)
{
	int	count;
	int	diff;
	int	itoa;
	int	dotzero;

	itoa = (int)ft_strlen(pf->fstr);
	diff = 0;
	dotzero = (pf->dot == 1 && nmb == 0) ? 1 : 0;
	if (pf->prec > 0 && pf->prec > (size_t)itoa)
		diff = (int)(pf->prec - itoa);
	count = pf->prec == (size_t)ft_strlen(pf->fstr) ? 1 : 0;
	if (pf->fldwt > (size_t)(itoa + diff) && pf->sp != 3)
		while (count++ < (int)(pf->fldwt - (itoa + diff + (pf->hash * 2) \
		- dotzero)))
			ft_putchar_pf(' ', pf);
	if (pf->fldwt > (size_t)(itoa + diff) && pf->sp == 3)
		while (count++ < (int)(pf->fldwt - (itoa + diff + (pf->hash * 2) - \
		dotzero + 3)))
			ft_putchar_pf(' ', pf);
}

void	nulintend_x(t_p *pf)
{
	size_t	count;

	count = 0;
	if (pf->fldwt > ft_strlen(pf->fstr) + (pf->hash * 2))
		while (count++ < (pf->fldwt - \
		(ft_strlen(pf->fstr) + (pf->hash * 2))))
			ft_putchar_pf('0', pf);
	pf->plus = 0;
	pf->nulchr = 0;
}

void	ft_precision_x(t_p *pf)
{
	int diff;

	diff = (int)(pf->prec - (ft_strlen(pf->fstr)));
	pf->plus = 0;
	while (diff-- > 0)
		ft_putchar_pf('0', pf);
}
