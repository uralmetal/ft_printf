/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:23:06 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/21 17:21:04 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# define CH_NULL(x) if((x) == NULL) exit(-1)
# define MIN(x) (1LL << (sizeof(x) * 8 - 1))

# include "ft_printf.h"
# include "libft/libft.h"
# include <stdarg.h>
#include <stdio.h>

typedef char *(*get_output)(const void*);

typedef struct		s_print
{
	char			flag[6];
	int				width;
	int				precision;
	char 			type[4];
}					t_print;

void		ft_printf(const char *fmt, ...);
get_output	get_function(t_print mod);
int 		print(t_print modif, const void *arg);
int 		parser(const char *fmt, va_list *ap, size_t *i);
char 		*min_integer(size_t size);
char		*ft_lltoa(long long n);
char		*ft_ulltoa(unsigned long long n);
char		*ulltohex(unsigned long long value);
char 		*ulltohex_upper(unsigned long long value);
char		*ulltooct(unsigned long long value);
char		*ulltobin(unsigned long long value);

char		*get_char(const void *arg);
char		*get_pointer(const void *arg);
char		*get_string(const void *arg);
char		*get_double(const void *arg, unsigned int precision);
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
