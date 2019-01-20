/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonett <gleonett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:55:49 by gleonett          #+#    #+#             */
/*   Updated: 2019/01/20 14:19:06 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void clean_flags(char *flgs, t_print *mod)
{
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
				if (mod->flag[j] == ' ' && true_flgs[1] == '+')
					break ;
				if (mod->flag[j] == '#' && (true_flgs[0] == '-' ||
				true_flgs[0] == '0' || true_flgs[1] == '0'))
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

void check_flags(t_print *mod, const char *fmt, size_t *i)
{
	char flgs[6] = "-+ 0#";
	int j;
	int k;

	*i += 1;
	k = 0;
	while (k < 6)
	{
		j = 0;
		k = 0;
		while (mod->flag[k] != '\0')
		{
			if (fmt[*i] == mod->flag[k])
			{
				*i += 1;
				k = 0;
			}
			else
				k++;
		}
		while (flgs[j] && fmt[*i] != flgs[j])
			j++;
		if (j < 5)
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
	if (mod->flag[0] == '\0')
		return ;
	clean_flags(flgs, mod);
}
