/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:23:06 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/30 09:30:36 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# define CH_NULL(x) if((x) == NULL) exit(-1)
# define CH_ERROR(x) if((x) == 1) {mod->error = 1; return(1);}
# define MIN(x) (1LL << (sizeof(x) * 8 - 1))
# define DAY_TO_SEC(days) ((days) * 60 * 60 * 24)
# define LEAP_YEAR(y) ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))
# define EPOCH(sec) (((sec) >= 0) ? (1) : (-1))
# define IF_D_DD(x) if(x == 10 || x == 11 || x == 24 || x == 37 || x == 38 ||\
x == 41 || x == 42 || x == 43 || x == 45 || x == 46 || x == 48 || x == 49 ||\
x == 51)

# include "ft_printf.h"
# include "libft/libft.h"
# include <stdarg.h>
#include <stdio.h>

typedef char *(*get_output)();
typedef long time_t;

typedef struct		s_print
{
	char			flag[6];
	int 			type;
	int				num_arg;
	int				width;
	int				width_num_arg;
	int				precision;
	int				prec_num_arg;
	int				error;
	size_t			i;
	struct	s_print	*next;
}					t_print;

int					g_output_symbols;
t_print				*start_list;
t_print				*mod;

int			ft_printf(const char *fmt, ...);
int			check_fmt(const char *fmt);
int 		parser(va_list ap, va_list start, size_t *i);
int 		number_of_argument(const char *fmt, size_t *i);
int			check_flags(t_print *mod, const char *fmt, size_t *i);
void		clean_flags(t_print *mod);
t_print		*init_list(void);
void		del_list(int fail);
int			find_d_dd(void);
void		va_arg_num(va_list start, int num_arg, void **p);
void		va_arg_num_int(va_list start, int num_arg, int *value);
void		va_arg_num_d(va_list start, int num_arg, double *var_d);
void		va_arg_num_dd(va_list start, int num_arg, long double *var_dd);
void		va_arg_width(va_list start, va_list ap);
void		va_arg_precision(va_list start, va_list ap);
get_output	get_function(t_print *mod);
int 		print(t_print *mod, const void *arg, double var_d, long double var_dd);
void		ft_putstr_full(const char *str);
void		ft_putnstr_full(const char *str, size_t n);
char 		*min_integer(size_t size);
char		*ft_lltoa(long long n);
char		*ft_ulltoa(unsigned long long n);
char		*ulltohex(unsigned long long value);
char 		*ulltohex_upper(unsigned long long value);
char		*ulltooct(unsigned long long value);
char		*ulltobin(unsigned long long value);
long		sign_double(double val);
char*		wchar_to_str(int sym);

char		*get_char(const void *arg);
char		*get_percent(const void *);
char		*get_pointer(const void *arg);
char		*get_string(const void *arg);
char		*get_string_with_non_print(const void *arg);
char 		*get_long_char(const void *arg);
char 		*get_long_string(const void *arg);
char		*get_date(const void *arg);
char		*get_double(double arg, unsigned int precision);
char		*get_long_double(long double a, unsigned int precision);
char		*get_double_exp(double arg, unsigned int precision);
char		*get_long_double_exp(long double arg, unsigned int precision);
char		*get_double_g(double arg, unsigned int precision);
char		*get_long_double_g(long double arg, unsigned int precision);
char		*get_double_hex(double arg);
char		*get_double_upper(double arg, unsigned int precision);
char		*get_double_exp_upper(double arg, unsigned int precision);
char		*get_double_g_upper(double arg, unsigned int precision);
char		*get_long_double_upper(long double arg, unsigned int precision);
char		*get_long_double_exp_upper(long double arg, unsigned int precision);
char		*get_long_double_g_upper(long double arg, unsigned int precision);
char		*get_double_hex_upper(double arg);
char		*get_long_double_hex(long double arg);
char		*get_long_double_hex_upper(long double arg);
char		*get_signed_char(const void *arg);
char		*get_short(const void *arg);
char		*get_int(const void *arg);
char		*get_long(const void *arg);
char 		*get_long_long(const void *arg);
char		*get_unsigned_char(const void *arg);
char		*get_unsigned_short(const void *arg);
char		*get_unsigned_int(const void *arg);
char		*get_unsigned_long(const void *arg);
char		*get_unsigned_long_long(const void *arg);
char		*get_unsigned_char_hex(const void *arg);
char		*get_unsigned_short_hex(const void *arg);
char		*get_unsigned_int_hex(const void *arg);
char		*get_unsigned_long_hex(const void *arg);
char		*get_unsigned_long_long_hex(const void *arg);
char		*get_unsigned_char_hex_upper(const void *arg);
char		*get_unsigned_short_hex_upper(const void *arg);
char		*get_unsigned_int_hex_upper(const void *arg);
char		*get_unsigned_long_hex_upper(const void *arg);
char		*get_unsigned_long_long_hex_upper(const void *arg);
char		*get_unsigned_char_oct(const void *arg);
char		*get_unsigned_short_oct(const void *arg);
char		*get_unsigned_int_oct(const void *arg);
char		*get_unsigned_long_oct(const void *arg);
char		*get_unsigned_long_long_oct(const void *arg);
char		*get_unsigned_char_bin(const void *arg);
char		*get_unsigned_short_bin(const void *arg);
char		*get_unsigned_int_bin(const void *arg);
char		*get_unsigned_long_bin(const void *arg);
char		*get_unsigned_long_long_bin(const void *arg);

#endif
