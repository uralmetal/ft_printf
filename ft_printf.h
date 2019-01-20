/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:23:06 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/20 18:05:13 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

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
	int 			type;
}					t_print;

void		ft_printf(const char *fmt, ...);
int			parser(const char *fmt, va_list *ap, size_t *i);
void		check_flags(t_print *mod, const char *fmt, size_t *i);
get_output	get_function(t_print mod);
int 		print(t_print modificators, const void *arg);
char		*get_char(const void *arg);
char		*get_pointer(const void *arg);
char		*get_string(const void *arg);
char		*get_int(const void *arg);

#endif
