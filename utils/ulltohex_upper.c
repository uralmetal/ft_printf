/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltohex_upper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:54:26 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/30 10:34:59 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ulltohex_upper(unsigned long long value)
{
	char		*ret;
	char		*temp;
	const int	size = 32;
	int			i;

	CH_NULL(temp = ft_strnew(size));
	symtohex_upper(value, temp, size);
	i = 0;
	while (temp[i] == '0' && i < size - 1)
		i++;
	ret = ft_strdup(temp + i);
	ft_strdel(&temp);
	return (ret);
}
