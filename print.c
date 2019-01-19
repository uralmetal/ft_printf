/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:01:34 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/19 19:17:01 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int add_flags(char **output, t_print modif)
{
	char flgs[][3] = {"-", "-+", "+-", "- ", " -", "+0", "0+", " ", " 0", "0 ",
	"0-", "-0"};
	int i;

	i = -1;
	while (++i < 10)
		if (ft_strcmp(modif.flag, flgs[i]) == 0)
			break ;
	if (i == 10)
	{
		printf("wrong flag: %%[%s]%s", modif.flag, modif.type);
		return (0);
	}
	return (1);
}

int print(t_print modif, const void *arg)
{
	get_output function_get;
	char *output;


	printf("flag = [%s]\nwidth = [%d]\nprecision = [%d]\ntype = [%s]\n",
		   modif.flag, modif.width, modif.precision, modif.type);
	if ((function_get = get_function(modif)) == NULL)
	{
		printf("Пока нет такой функции, напиши ее, заебал <3");
		return (0);
	}
	output = function_get(arg);
	if (add_flags(&output, modif) == 0)
	{
		ft_strdel(&output);
		return (0);
	}
	ft_putstr(output);
	ft_strdel(&output);
	return (1);
}
