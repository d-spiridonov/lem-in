/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:36:00 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/15 19:38:03 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char(va_list args, t_p *pf)
{
	unsigned char	val;
	size_t			count;

	count = 0;
	val = va_arg(args, int);
	if (pf->fldwt > 0 && pf->min == 0 && pf->nulchr == 0)
		while (count++ < (pf->fldwt - 1))
			ft_putchar_pf(' ', pf);
	if (pf->nulchr == 1 && pf->min == 0)
		while (count++ < pf->fldwt - 1)
			ft_putchar_pf('0', pf);
	ft_putchar_pf(val, pf);
	if (pf->min > 0)
		while (count++ < (pf->fldwt - 1))
			ft_putchar_pf(' ', pf);
	return (0);
}

void	ft_p_hexa(va_list args, t_p *pf)
{
	unsigned long long	val;

	val = ft_modifier_o(args, &*pf);
	ft_itoa_base_o(val, 16, pf);
	if ((pf->fldwt > 0 && pf->min == 0 && pf->prec < pf->fldwt && \
	pf->nulchr == 0))
		indent_p(val, pf);
	if ((pf->hash == 1 && (pf->sp == 7 || pf->sp == 8 \
	|| pf->sp == 11 || pf->sp == 12 || pf->sp == 3)))
		ft_zerobefore(val, pf);
	if (val != 0 || pf->dot != 1 || pf->dot > 0)
	{
		if (pf->dot == 1)
			ft_precision_p(pf);
		if (pf->nulchr == 1 && pf->min == 0 && pf->dot == 0)
			nulintend_p(pf);
		if (pf->prec != 0 || pf->dot == 0 || val != 0)
			ft_putstr_pf(pf->fstr, pf);
		if (pf->fldwt > pf->prec && pf->min > 0)
			indent_p(val, pf);
	}
}

void	ft_wchar(va_list args, t_p *pf)
{
	int val;

	val = va_arg(args, int);
	if (val == 0)
		pf->ret = pf->ret + write(1, &val, 1);
	pf->fstr = ft_strnew((countwchar(val) + 1));
	getwchar(val, pf->fstr);
	if (pf->fldwt > 0 && pf->min == 0 && pf->nulchr == 0)
		indent_s(pf->fstr, pf);
	if (pf->nulchr == 1 && pf->min == 0)
		nulintend_s(pf->fstr, pf);
	ft_putstr_pf(pf->fstr, pf);
	if (pf->fldwt > pf->prec && pf->min > 0)
		indent_s(pf->fstr, pf);
}

void	ft_wcharstr(va_list args, t_p *pf)
{
	int	*val;

	if ((val = va_arg(args, int*)))
	{
		pf->fstr = ft_strnew((countwcharstr(val) + 1));
		getwcharstr(val, pf->fstr, 0);
		if (pf->prec > 0)
			ft_precisioncorr(val, pf);
		if (pf->fldwt > 0 && pf->min == 0 && pf->nulchr == 0)
			indent_s(pf->fstr, pf);
		if (pf->nulchr == 1 && pf->min == 0)
			nulintend_s(pf->fstr, pf);
		if (pf->prec > 0)
			ft_precision_w(pf->fstr, pf, val, 0);
		if (pf->dot == 0)
			ft_putstr_pf(pf->fstr, pf);
		if (pf->fldwt > pf->prec && pf->min > 0)
			indent_s(pf->fstr, pf);
	}
	else
		pf->ret = pf->ret + ft_printf("(null)");
}
