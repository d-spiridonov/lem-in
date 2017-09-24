/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:38:29 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/15 20:07:43 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_precision_print(char *str, t_p *pf, size_t *i, int size)
{
	int a;

	a = 0;
	while (a++ < size)
		ft_putchar_pf(str[(*i)++], pf);
}

void		ft_precision_w(char *str, t_p *pf, int *val, size_t i)
{
	while (*val && i < pf->prec)
	{
		if (*val < 127 && (i + 1) <= pf->prec)
			ft_putchar_pf(str[i++], pf);
		else if (*val < 2048 && (i + 2) <= pf->prec)
			ft_precision_print(str, pf, &i, 2);
		else if (*val < 65536 && (i + 3) <= pf->prec)
			ft_precision_print(str, pf, &i, 3);
		else if (*val < 1114112 && (i + 4) <= pf->prec)
			ft_precision_print(str, pf, &i, 4);
		else
			i += 4;
		val++;
	}
}

void		ft_precisioncorr(int *val, t_p *pf)
{
	size_t i;

	i = 0;
	while (*val)
	{
		if (*val < 127 && i + 1 <= pf->prec)
			i++;
		else if (*val < 2048 && i + 2 <= pf->prec)
			i += 2;
		else if (*val < 65536 && i + 3 <= pf->prec)
			i += 3;
		else if (*val < 1114112 && i + 4 <= pf->prec)
			i += 4;
		else
			break ;
		val++;
	}
	pf->prec = i;
}

size_t		countwchar(int val)
{
	size_t count;

	count = 0;
	if (val < 127)
		count++;
	else if (val < 2048)
		count += 2;
	else if (val < 65536)
		count += 3;
	else if (val < 1114112)
		count += 4;
	return (count);
}

void		getwchar(int val, char *str)
{
	int i;

	i = 0;
	if (val < 127)
		str[i++] = (char)val;
	else if (val < 2048)
	{
		str[i++] = (char)(192 | val >> 6);
		str[i++] = (char)(128 | (63 & val));
	}
	else if (val < 65536)
	{
		str[i++] = (char)(224 | val >> 12);
		str[i++] = (char)(128 | (63 & val >> 6));
		str[i++] = (char)(128 | (63 & val));
	}
	else if (val < 1114112)
	{
		str[i++] = (char)(240 | val >> 18);
		str[i++] = (char)(128 | (63 & val >> 12));
		str[i++] = (char)(128 | (63 & val >> 6));
		str[i++] = (char)(128 | (63 & val));
	}
	str[i] = '\0';
}
