/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grbrg_collct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:30:01 by enaam             #+#    #+#             */
/*   Updated: 2023/11/19 11:37:09 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	free_garbg(t_list **cont)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*cont))
		return ;
	tmp = *cont;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = tmp2;
	}
}

t_list	*ft_grbg_new(void *content)
{
	t_list	*start;

	start = (t_list *)malloc(sizeof(t_list));
	if (!start)
		return (0);
	start->content = content;
	start->next = NULL;
	return (start);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
