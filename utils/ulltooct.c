/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltooct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:00:10 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/21 16:00:10 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	symtooct(unsigned long long c, char *hex, unsigned int size)
{
	int value;
	int count;

	count = size - 1;
	while (count >= 0)
		hex[count--] = '0';
	count = size - 1;
	while (c > 0)
	{
		value = c;
		c = c / 8;
		value = value - c * 8;
		hex[count--] = '0' + value;
	}
}

char	*ulltooct(unsigned long long value)
{
	char *ret;
	const int size = 45;
	int i;

	CH_NULL(ret = ft_strnew(size));
	symtooct(value, ret, size);
	i = 0;
	while (ret[i] == '0' && i < size - 1)
		i++;
	return (ret + i);
}