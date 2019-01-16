/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:49:29 by rwalder-          #+#    #+#             */
/*   Updated: 2018/11/27 14:52:35 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void*, size_t))
{
	t_list *next;
	t_list **p;

	if (*alst != NULL)
	{
		p = alst;
		while (*p)
		{
			next = (*p)->next;
			del((*alst)->content, (*alst)->content_size);
			(*alst)->content = NULL;
			(*alst)->content_size = 0;
			(*p)->next = NULL;
			free(*p);
			*p = next;
		}
	}
}
