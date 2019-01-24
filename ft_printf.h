/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:23:06 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/23 14:37:40 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# define CH_NULL(x) if((x) == NULL) exit(-1)
# define MIN(x) (1LL << (sizeof(x) * 8 - 1))
#define DAY_TO_SEC(days) ((days) * 60 * 60 * 24)
#define LEAP_YEAR(y) ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))
#define EPOCH(sec) (((sec) >= 0) ? (1) : (-1))

# include "ft_printf.h"
# include "libft/libft.h"
# include <stdarg.h>
#include <stdio.h>

typedef char *(*get_output)();
typedef long time_t;

typedef struct		s_print
{
	char			flag[6];
	int				width;
	int				precision;
	int 			type;
	int				num_arg;
	int				width_num_arg;
	int				prec_num_arg;
}					t_print;

void		ft_printf(const char *fmt, ...);
int			parser(const char *fmt, va_list ap, va_list start, size_t *i);
int 		number_of_argument(const char *fmt, size_t *i);
int			check_flags(t_print *mod, const char *fmt, size_t *i);
void		clean_flags(t_print *mod);
get_output	get_function(t_print *mod);
int 		print(t_print *mod, const void *arg);
void		ft_putstr_full(const char *str);
void		ft_putnstr_full(const char *str, size_t n);
char 		*min_integer(size_t size);
char		*ft_lltoa(long long n);
char		*ft_ulltoa(unsigned long long n);
char		*ulltohex(unsigned long long value);
char 		*ulltohex_upper(unsigned long long value);
char		*ulltooct(unsigned long long value);
char		*ulltobin(unsigned long long value);

char		*get_char(const void *arg);
char		*get_percent(const void *);
char		*get_pointer(const void *arg);
char		*get_string(const void *arg);
char		*get_string_with_non_print(const void *arg);
char		*get_date(const void *arg);
char		*get_double(const void *arg, unsigned int precision);
char		*get_float(const void *arg, unsigned int precision);
char 		*get_long_double(const void *arg, unsigned int precision);
char		*get_double_exp(const void *arg, unsigned int precision);
char		*get_double_g(const void *arg, unsigned int precision);
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
