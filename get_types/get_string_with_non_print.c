/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_with_non_printable.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 09:17:33 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/30 10:21:29 by gleonett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char *add_char_non_print(char **str, unsigned char sym)
{
	char *ret;
	char *code_sym;
	int len;

	ret = ft_itoa(sym);
	len = ft_strlen(ret);
	if (len == 3)
		code_sym = ft_strjoin("\\", ret);
	else if (len == 2)
		code_sym = ft_strjoin("\\0", ret);
	else if (len == 1)
		code_sym = ft_strjoin("\\00", ret);
	ft_strdel(&ret);
	ret = ft_strjoin(*str, code_sym);
	ft_strdel(str);
	*str = ret;
	return (ret);
}


char	*get_string_with_non_print(const void *arg)
{
	const char **s = (const char**)arg;
	int i;
	char *ret;
	char *sub;
	char *temp;
	int len;
	int start;

	i = 0;
	len = 0;
	ret = ft_strnew(1);
	start = 0;
	while ((*s)[i] != '\0')
	{
		if (((*s)[i] < ' ' || (*s)[i] > '~') && len != 0)
		{
			sub = ft_strsub(*s, start, len);
			temp = ft_strjoin(ret, sub);
			ft_strdel(&ret);
			ret = temp;
		}
		if ((*s)[i] < ' ' || (*s)[i] > '~')
		{
			ret = add_char_non_print(&ret, (unsigned char)(*s)[i]);
			len = 0;
			start = i + 1;
		}
		else
			len++;
		i++;
	}
	sub = ft_strsub(*s, start, len);
	temp = ft_strjoin(ret, sub);
	ft_strdel(&ret);
	ret = temp;
	return (ret);
}