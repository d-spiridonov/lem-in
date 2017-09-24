/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:56:48 by dspyrydo          #+#    #+#             */
/*   Updated: 2017/06/14 19:57:10 by dspyrydo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct		s_p
{
	size_t			min;
	size_t			fldwt;
	size_t			plus;
	size_t			dot;
	size_t			prec;
	size_t			space;
	size_t			hash;
	size_t			nulchr;
	size_t			size_m;
	size_t			ret;
	int				sp;
	char			*fstr;
}					t_p;

int					specprocess(va_list args, t_p *pf, int sp);
int					fmt(va_list args, const char *restrict format, int *i, \
					t_p *pf);
int					ft_write(va_list args, const char *restrict format);
int					ft_printf(const char *restrict format, ...);
void				indent_d(long long int nmb, t_p *pf);
void				ft_precision_d(long long int *val, t_p *pf);
void				ft_decimal(va_list args, t_p *pf);
int					type_s(char c, t_p *pf);
void				plusflag(int *i, t_p *pf);
int					fieldwidth(const char *format, int *i, t_p *pf);
void				precision(const char *format, int *i, t_p *pf);
void				space(int *i, t_p *pf);
int					flags(const char *restrict format, int *i, t_p *pf);
void				nul(int *i, t_p *pf);
void				hash(int *i, t_p *pf);
int					sizemodifier(const char *format, int *i, t_p *pf);
void				ft_string(va_list args, t_p *pf);
void				zero_pf(t_p *pf);
void				ft_putnbr_u(unsigned int n);
void				nulintend_d(long long int nmb, t_p *pf);
int					ft_itoa_base(long long int value, int base, t_p *pf);
unsigned long long	ft_modifier_o(va_list args, t_p *pf);
long long			ft_modifier_d(va_list args, t_p *pf);
void				ft_octal(va_list args, t_p *pf, int base, \
					unsigned long long val);
void				indent_o(long long int nmb, t_p *pf);
void				nulintend_o(t_p *pf);
void				ft_precision_o(long long int val, t_p *pf);
int					ft_itoa_base_o(long long int value, int base, t_p *pf);
void				ft_hexa(va_list args, t_p *pf);
void				indent_x(long long int nmb, t_p *pf);
void				nulintend_x(t_p *pf);
void				ft_precision_x(t_p *pf);
void				indent_c(t_p *pf);
void				ft_zerobefore(long long int val, t_p *pf);
void				indent_s(char *str, t_p *pf);
void				ft_precision_s(char *str, t_p *pf);
int					ft_char(va_list args, t_p *pf);
void				nulintend_c(t_p *pf);
int					formatparser(const char *str, int i);
void				nulintend_s(char *str, t_p *pf);
void				ft_p_hexa(va_list args, t_p *pf);
void				ft_precision_p(t_p *pf);
void				indent_p(long long int nmb, t_p *pf);
void				nulintend_p(t_p *pf);
void				ft_notype(const char *restrict format, t_p *pf, int *i);
void				ft_putchar_pf(char c, t_p *pf);
void				ft_putstr_pf(char const *s, t_p *pf);
void				ft_wchar(va_list args, t_p *pf);
size_t				countwcharstr(int *val);
void				getwcharstr(int *val, char *str, int i);
void				ft_wcharstr(va_list args, t_p *pf);
void				ft_precision_w(char *str, t_p *pf, int *val, size_t i);
size_t				countwchar(int val);
void				getwchar(int val, char *str);
void				ft_precisioncorr(int *val, t_p *pf);
int					flagparser(const char *format, int i);
void				put0x(t_p *pf);

#endif
