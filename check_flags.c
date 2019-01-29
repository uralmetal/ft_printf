/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:55:49 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/29 18:59:59 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void clean_flags(t_print *mod)
{
	const char flgs[7] = "-+ 0#'";
	char true_flgs[6];
	int i;
	int j;
	int k;

	i = -1;
	k = -1;
	ft_bzero(true_flgs, 6);
	while (flgs[++i] != '\0')
	{
		j = -1;
		while (mod->flag[++j] != '\0')
			if (mod->flag[j] == flgs[i])
			{
				if (mod->flag[j] == '0' && true_flgs[0] == '-')
					break ;
				if (mod->flag[j] == ' ' && (true_flgs[0] == '+' ||
				true_flgs[1] == '+'))
					break ;
				if (mod->flag[j] == '#' && (true_flgs[0] == '-'))
				{
					true_flgs[0] = '#';
					break;
				}
				true_flgs[++k] = flgs[i];
			}
	}
	ft_bzero(mod->flag, 6);
	ft_strcpy(mod->flag, true_flgs);
}

int number_of_argument(const char *fmt, size_t *i)
{
	size_t j;
	int ret;

	j = *i;
	while (fmt[j] >= '0' && fmt[j] <= '9')
		j++;
	if (fmt[j] != '$')
		return (0);
	ret = ft_atoi(fmt + *i);
	*i = j + 1;
	return (ret);
}

int check_flags(t_print *mod, const char *fmt, size_t *i)
{
	char flgs[10] = "-+ 0#'";
	int j;
	int k;

	k = 0;
	while (k < 7)
	{
		j = 0;
		k = 0;
		while (mod->flag[k] != '\0')
		{
			if (fmt[*i] == mod->flag[k] && fmt[*i] != '%')
			{
				*i += 1;
				k = 0;
			}
			else
				k++;
		}
		if (fmt[*i] >= '1' && fmt[*i] <= '9')
			mod->num_arg = number_of_argument(fmt, i);
		while (fmt[*i] != flgs[j] && flgs[j])
			j++;
		if (flgs[j] != '\0')
		{
			mod->flag[k] = flgs[j];
			*i += 1;
		}
		else
		{
			mod->flag[k] = '\0';
			break ;
		}
	}
	return (0);
}
