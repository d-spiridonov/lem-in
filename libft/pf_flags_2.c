/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 19:16:39 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/14 19:18:05 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nul(int *i, t_p *pf)
{
	pf->nulchr = 1;
	(*i)++;
}

void	hash(int *i, t_p *pf)
{
	pf->hash = 1;
	(*i)++;
}

int		sizemodifier(const char *format, int *i, t_p *pf)
{
	if (format[(*i)] == 'h' && flagparser(format, *i) == 0 && pf->size_m == 0)
		pf->size_m = 2;
	if (format[(*i)] == 'h' && flagparser(format, *i) == 1 && pf->size_m < 2)
		pf->size_m = 1;
	if (format[(*i)] == 'l' && flagparser(format, *i) == 0 && pf->size_m < 4)
		pf->size_m = 3;
	if (format[(*i)] == 'l' && flagparser(format, *i) == 1 && pf->size_m < 5)
		pf->size_m = 4;
	if (format[(*i)] == 'j' && pf->size_m < 6)
		pf->size_m = 5;
	if (format[(*i)] == 'z' && pf->size_m < 7)
		pf->size_m = 6;
	(*i)++;
	return (0);
}
