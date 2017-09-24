/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 16:44:12 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/05/14 16:49:21 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		plusflag(int *i, t_p *pf)
{
	pf->plus = 1;
	(*i)++;
}

int			fieldwidth(const char *format, int *i, t_p *pf)
{
	pf->fldwt = 0;
	while (ft_isdigit(format[*i]) == 1 && format[*i] != '.' && \
	ft_isalpha(format[*i]) != 1)
		pf->fldwt = pf->fldwt * 10 + format[(*i)++] - 48;
	return (0);
}

void		precision(const char *format, int *i, t_p *pf)
{
	pf->prec = 0;
	pf->dot = 1;
	(*i)++;
	while (ft_isdigit(format[*i]) == 1)
		pf->prec = pf->prec * 10 + format[(*i)++] - 48;
}

void		space(int *i, t_p *pf)
{
	pf->space = 1;
	(*i)++;
}

int			flags(const char *restrict format, int *i, t_p *pf)
{
	(*i)++;
	while (ft_strchr("+-#* .0123456789hljz", format[*i]))
	{
		if (format[(*i)] == '-')
			pf->min = 1;
		if (format[(*i)] == '+')
			plusflag(i, &*pf);
		else if (format[(*i)] == ' ')
			space(i, &*pf);
		else if (format[(*i)] == '#')
			hash(i, &*pf);
		else if (format[(*i)] == '0')
			nul(i, &*pf);
		else if (ft_isdigit(format[*i]) == 1)
			fieldwidth(format, i, &*pf);
		else if (format[*i] == '.')
			precision(format, i, &*pf);
		else if (format[*i] == 'h' || format[*i] == 'l' || format[*i] == 'j' \
			|| format[*i] == 'z')
			sizemodifier(format, i, &*pf);
		else
			(*i)++;
	}
	return (0);
}
