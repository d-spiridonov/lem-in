/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 20:11:11 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/14 20:12:43 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		formatparser(const char *str, int i)
{
	int		percent;

	percent = 0;
	while (i != -1 && (!ft_strchr("sSpdDioOuUxXcC", str[i])))
	{
		if (ft_isalpha(str[i]) == 1 && percent < 2)
			return (-1);
		else if (str[i--] == '%')
			percent++;
	}
	if (percent % 2 == 0 && percent != 0)
		return (0);
	else
		return (-1);
}

void	nulintend_s(char *str, t_p *pf)
{
	size_t count;
	size_t len;

	len = (str == NULL) ? 0 : ft_strlen(str);
	count = 0;
	if (pf->fldwt > len && pf->prec == 0)
		while (count++ < pf->fldwt - len)
			ft_putchar_pf('0', pf);
	else if (pf->dot > 0 && len > pf->prec && pf->fldwt > pf->prec)
		while (count++ < pf->fldwt - pf->prec)
			ft_putchar_pf('0', pf);
}

void	ft_notype(const char *restrict format, t_p *pf, int *i)
{
	if (pf->fldwt > 0 && pf->min == 0 && pf->nulchr == 0)
		indent_c(pf);
	if (pf->nulchr == 1 && pf->min == 0 && pf->prec == 0)
		nulintend_c(pf);
	if (ft_strchr("%", format[*i]) == NULL)
		ft_putchar_pf(format[(*i)], pf);
	if (pf->min > 0)
		indent_c(pf);
	(*i)++;
}

size_t	countwcharstr(int *val)
{
	size_t count;

	count = 0;
	if (val != NULL)
	{
		while (*val)
		{
			if (*val < 127)
				count++;
			else if (*val < 2048)
				count += 2;
			else if (*val < 65536)
				count += 3;
			else if (*val < 1114112)
				count += 4;
			val++;
		}
	}
	return (count);
}

void	getwcharstr(int *val, char *str, int i)
{
	while (*val)
	{
		if (*val < 127)
			str[i++] = (char)*val;
		else if (*val < 2048)
		{
			str[i++] = (char)(192 | *val >> 6);
			str[i++] = (char)(128 | (63 & *val));
		}
		else if (*val < 65536)
		{
			str[i++] = (char)(224 | *val >> 12);
			str[i++] = (char)(128 | (63 & *val >> 6));
			str[i++] = (char)(128 | (63 & *val));
		}
		else if (*val < 1114112)
		{
			str[i++] = (char)(240 | *val >> 18);
			str[i++] = (char)(128 | (63 & *val >> 12));
			str[i++] = (char)(128 | (63 & *val >> 6));
			str[i++] = (char)(128 | (63 & *val));
		}
		val++;
	}
	str[i] = '\0';
}
