/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:23:06 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/17 16:42:09 by rwalder-         ###   ########.fr       */
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
	int				width;
	unsigned int	precision;
	char 			type[4];
}					t_print;

void		ft_printf(char *s);
get_output	get_function(char *type);
void 		print(t_print modificators, const void *arg);
char		*get_char(const void *arg);
char		*get_pointer(const void *arg);

#endif
