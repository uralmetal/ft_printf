/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:23:06 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/21 14:18:52 by rwalder-         ###   ########.fr       */
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
char		*get_char(const void *arg);
char		*get_pointer(const void *arg);
char		*get_string(const void *arg);
char		*get_double(const void *arg, unsigned int precision);
char 		*get_date(const char *arg);

#endif
