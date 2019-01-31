/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_long_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:40:02 by rwalder-          #+#    #+#             */
/*   Updated: 2019/01/30 15:47:42 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*get_long_string(const void *arg)
{
	int			i;
	const int	**wstr = (const int **)arg;
	char		*ret;
	char		*join;
	char		*temp;

	if (*wstr == NULL)
		return (ft_strdup("(null)"));
	i = 0;
	ret = ft_strdup("");
	while ((*wstr)[i] != 0)
	{
		temp = wchar_to_str((*wstr)[i++]);
		join = ft_strjoin(ret, temp);
		ft_strdel(&temp);
		ft_strdel(&ret);
		ret = join;
	}
	return (ret);
}
