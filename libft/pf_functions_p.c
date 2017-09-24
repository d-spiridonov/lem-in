/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 20:15:02 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/14 20:16:53 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_p(t_p *pf)
{
	int diff;

	diff = (int)(pf->prec - (ft_strlen(pf->fstr)));
	pf->plus = 0;
	while (diff-- > 0)
		ft_putchar_pf('0', pf);
}

void	indent_p(long long int nmb, t_p *pf)
{
	int	count;
	int	diff;
	int	itoa;

	itoa = 2;
	count = 0;
	diff = 0;
	if (pf->prec < ft_strlen(pf->fstr))
		itoa = (int)ft_strlen(pf->fstr);
	if (pf->prec >= 2)
		diff = pf->prec;
	if ((pf->prec < 2 && nmb > 0) || (pf->dot == 0 && nmb == 0))
		diff += 2;
	if (nmb == 0 && pf->prec < 2 && pf->dot == 1)
		diff++;
	while (count++ < (int)(pf->fldwt - (diff + itoa)))
		ft_putchar_pf(' ', pf);
}

void	nulintend_p(t_p *pf)
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
