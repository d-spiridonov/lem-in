/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:07:04 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/14 19:41:18 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_negative(long long int value)
{
	if (value < 0)
		return (-1);
	else
		return (0);
}

static void		ft_base(unsigned long long value, int base, t_p *pf, char **str)
{
	unsigned long long	remainder;
	unsigned long long	tmp;
	int					i;

	i = 0;
	tmp = value;
	*str = (char*)malloc(sizeof(*str) * (ft_countdigits(tmp) + pf->hash \
	+ 2));
	if (value == 0)
		(*str)[i++] = 48;
	while (tmp > 0)
	{
		remainder = tmp % base;
		tmp /= base;
		if (remainder > 9 && (pf->sp == 11 || pf->sp == 3))
			remainder += 39;
		if (remainder > 9 && pf->sp == 12)
			remainder += 7;
		(*str)[i++] = (char)(remainder + 48);
	}
	(*str)[i] = '\0';
}

static void		reverse(char *dst, char *src)
{
	int a;
	int i;

	i = 0;
	a = 0;
	while (src[i])
		i++;
	i--;
	while (i > -1)
		dst[a++] = src[i--];
	dst[a] = '\0';
	if (src != NULL)
		ft_strdel(&src);
}

int				ft_itoa_base(long long int value, int base, t_p *pf)
{
	char				*str;
	unsigned long long	nmb;

	str = NULL;
	if (pf->plus == 1 && pf->sp < 7)
		ft_putchar_pf('+', pf);
	if (value < 0 && ((pf->nulchr != 1 && (int)pf->prec == 0) \
	|| (pf->min == 1 && pf->nulchr == 1)))
		ft_putchar_pf('-', pf);
	if (base < 2 || base > 16)
		return (-1);
	if (ft_negative(value) == -1 && base == 10)
		nmb = (unsigned long long int)value * -1;
	else if (ft_negative(value) == -1 && base != 10)
		nmb = (unsigned long long int)value * -1;
	else
		nmb = (unsigned long long int)value;
	ft_base(nmb, base, pf, &str);
	pf->fstr = (char*)malloc(sizeof(*str) * (ft_countdigits(nmb) + 2));
	reverse(pf->fstr, str);
	return (0);
}

int				ft_itoa_base_o(long long int value, int base, t_p *pf)
{
	char			*str;
	unsigned long	nmb;

	str = NULL;
	if (base < 2 || base > 16)
		return (-1);
	nmb = (unsigned long long int)value;
	ft_base(nmb, base, pf, &str);
	pf->fstr = (char*)malloc(sizeof(*str) * (17));
	reverse(pf->fstr, str);
	return (0);
}
