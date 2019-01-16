/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:23:06 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/16 13:44:57 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "ft_printf.h"
# include "libft/libft.h"

void ft_printf(char *s);
void print_char(unsigned char c);
void print_string(const char *str);
void print_pointer(const void *p);

#endif
