/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:23:06 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/17 16:48:32 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "ft_printf.h"
# include "libft/libft.h"

typedef char* (*get_output)(const void*);

typedef struct		s_print
{
	char			flag;
	unsigned int	width;
	unsigned int	precision;
	char 			type[4];
}					t_print;

void		ft_printf(char *s);
get_output	get_function(t_print mod);
void 		print(t_print modificators, const void *arg);
char		*get_char(const void *arg);
char		*get_pointer(const void *arg);
char		*get_string(const void *arg);
char		*get_double(const void *arg);

#endif
