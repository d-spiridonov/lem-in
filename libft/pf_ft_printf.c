/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:04:34 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/14 19:47:23 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specprocess(va_list args, t_p *pf, int sp)
{
	if (pf->plus == 1 && pf->space == 1)
		pf->space = 0;
	else if (pf->sp == 5 || pf->sp == 10 || pf->sp == 8)
		pf->size_m = 3;
	else if (pf->sp == 3)
	{
		pf->size_m = 3;
		pf->hash = 1;
		ft_p_hexa(args, &*pf);
	}
	if (sp == 2 || (sp == 1 && pf->size_m == 3))
		ft_wcharstr(args, &*pf);
	else if (sp == 1)
		ft_string(args, &*pf);
	else if (sp == 4 || sp == 5 || sp == 6)
		ft_decimal(args, &*pf);
	else if (sp == 7 || sp == 8 || sp == 9 || sp == 10)
		ft_octal(args, &*pf, 16, 0);
	else if (sp == 11 || sp == 12)
		ft_hexa(args, &*pf);
	else if (sp == 14 || (pf->sp == 13 && pf->size_m == 3))
		ft_wchar(args, pf);
	else if (sp == 13)
		ft_char(args, &*pf);
	return (0);
}

int	fmt(va_list args, const char *restrict format, int *i, t_p *pf)
{
	if (format[*i] == '%' && formatparser(format, *i) == -1)
		flags(format, &*i, pf);
	if (type_s(format[*i], &*pf) > 0 && *i <= (int)ft_strlen(format))
		specprocess(args, &*pf, type_s(format[(*i)++], pf));
	if (ft_strchr("sSpdDioOuUxXcC", format[*i]) == NULL \
	&& *i <= (int)ft_strlen(format) && pf->sp == 0)
		ft_notype(format, &*pf, &*i);
	if (pf->sp < 0)
	{
		if (pf->fldwt > 0 && pf->min == 0 && pf->nulchr == 0)
			indent_c(pf);
		if (pf->nulchr == 1 && pf->min == 0)
			nulintend_c(pf);
		if (formatparser(format, *i) == 0)
			ft_putchar_pf(format[(*i)], pf);
		if (pf->min > 0)
			indent_c(pf);
		(*i)++;
	}
	if (pf->fstr != NULL && pf->sp != 1 && pf->sp != -1)
		ft_strdel(&pf->fstr);
	return (0);
}

int	ft_write(va_list args, const char *restrict format)
{
	int i;
	t_p	pf;

	i = 0;
	pf.ret = 0;
	while (format[i] != '\0' && i <= (int)ft_strlen(format))
	{
		zero_pf(&pf);
		if (format[i] == '%')
			fmt(args, format, &i, &pf);
		if (format[i] != '\0' && format[i] != '%' \
			&& i <= (int)ft_strlen(format))
			pf.ret = (pf.ret + write(1, &format[i++], 1));
	}
	return (int)(pf.ret);
}

int	ft_printf(const char *restrict format, ...)
{
	int		i;
	va_list args;

	va_start(args, format);
	i = ft_write(args, format);
	va_end(args);
	return (i);
}
