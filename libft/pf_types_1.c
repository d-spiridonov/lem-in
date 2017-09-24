/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 18:57:31 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/15 19:35:02 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(va_list args, t_p *pf)
{
	unsigned long long	val;

	val = ft_modifier_o(args, &*pf);
	ft_itoa_base_o(val, 16, pf);
	if (((pf->fldwt > 0 && pf->min == 0) && (pf->prec < pf->fldwt \
	&& pf->nulchr == 0)) || (pf->nulchr == 1 && pf->dot == 1))
		indent_x(val, pf);
	if ((pf->hash == 1 && (pf->sp == 7 || pf->sp == 8 \
	|| pf->sp == 11 || pf->sp == 12 || pf->sp == 3)))
		ft_zerobefore(val, pf);
	if (val != 0 || pf->dot != 1 || pf->prec > 0)
	{
		if (pf->prec > 0)
			ft_precision_x(pf);
		if (pf->nulchr == 1 && pf->min == 0 && pf->dot == 0)
			nulintend_x(pf);
		ft_putstr_pf(pf->fstr, pf);
		if (pf->fldwt > pf->prec && pf->min > 0)
			indent_x(val, pf);
	}
}

void	ft_octal(va_list args, t_p *pf, int base, unsigned long long val)
{
	if (pf->sp == 7 || pf->sp == 8)
		base = 8;
	if (pf->sp == 9 || pf->sp == 10)
		base = 10;
	val = ft_modifier_o(args, &*pf);
	ft_itoa_base_o(val, base, pf);
	if (((pf->fldwt > 0 && pf->min == 0) && (pf->prec < pf->fldwt && \
	pf->nulchr == 0)) || (pf->nulchr == 1 && pf->dot == 1))
		indent_o(val, pf);
	if (val != 0 || pf->dot != 1 || pf->hash || pf->prec > 0)
	{
		if (pf->hash == 1)
			ft_zerobefore(val, pf);
		if (pf->prec > 0)
			ft_precision_o(val, pf);
		if (pf->nulchr == 1 && pf->min == 0 && pf->dot == 0)
			nulintend_o(pf);
		ft_putstr_pf(pf->fstr, pf);
		if (pf->fldwt > pf->prec && pf->min > 0)
			indent_o(val, pf);
	}
}

void	ft_decimal(va_list args, t_p *pf)
{
	long long int	val;

	val = ft_modifier_d(args, &*pf);
	if (val < 0)
	{
		pf->space = 0;
		pf->plus = 0;
	}
	if (pf->space == 1 && pf->plus == 0)
		ft_putchar_pf(' ', pf);
	if (((pf->fldwt > 0 && pf->min == 0) && ((pf->prec < pf->fldwt && \
		pf->nulchr == 0))) || (pf->nulchr == 1 && pf->dot == 1 && pf->min == 0))
		indent_d(val, pf);
	if (val != 0 || pf->dot != 1 || pf->prec > 0)
	{
		if (pf->prec > 0)
			ft_precision_d(&val, pf);
		ft_itoa_base(val, 10, pf);
		if (pf->nulchr == 1 && pf->min == 0 && pf->dot == 0)
			nulintend_d(val, pf);
		ft_putstr_pf(pf->fstr, pf);
		if (pf->fldwt > pf->prec && pf->min > 0)
			indent_d(val, pf);
	}
}

void	ft_string(va_list args, t_p *pf)
{
	pf->fstr = va_arg(args, char*);
	if (pf->fstr == NULL && pf->nulchr == 0)
		pf->fstr = "(null)";
	if (pf->fldwt > 0 && pf->min == 0 && pf->nulchr == 0)
		indent_s(pf->fstr, pf);
	if (pf->nulchr == 1 && pf->min == 0)
		nulintend_s(pf->fstr, pf);
	if (pf->prec > 0)
		ft_precision_s(pf->fstr, pf);
	if (pf->dot == 0)
		ft_putstr_pf(pf->fstr, pf);
	if (pf->fldwt > pf->prec && pf->min > 0)
		indent_s(pf->fstr, pf);
}

int		type_s(char c, t_p *pf)
{
	int	sp;

	sp = 0;
	sp = (c == 's') ? 1 : sp;
	sp = (c == 'S') ? 2 : sp;
	sp = (c == 'p') ? 3 : sp;
	sp = (c == 'd') ? 4 : sp;
	sp = (c == 'D') ? 5 : sp;
	sp = (c == 'i') ? 6 : sp;
	sp = (c == 'o') ? 7 : sp;
	sp = (c == 'O') ? 8 : sp;
	sp = (c == 'u') ? 9 : sp;
	sp = (c == 'U') ? 10 : sp;
	sp = (c == 'x') ? 11 : sp;
	sp = (c == 'X') ? 12 : sp;
	sp = (c == 'c') ? 13 : sp;
	sp = (c == 'C') ? 14 : sp;
	sp = (c == '%') ? -1 : sp;
	pf->sp = sp;
	return (sp);
}
