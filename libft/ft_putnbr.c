/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:47:18 by rwalder-          #+#    #+#             */
/*   Updated: 2018/11/29 11:56:45 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		count;
	char	ret[20];
	long	num;

	count = 0;
	num = n;
	while (count < 20)
		ret[count++] = 0;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (num > 0)
	{
		ret[--count] = '0' + (num % 10);
		num = num / 10;
	}
	while (count < 20)
		ft_putchar(ret[count++]);
}
