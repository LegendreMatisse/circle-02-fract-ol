/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:34:15 by mlegendr          #+#    #+#             */
/*   Updated: 2023/02/06 15:34:53 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_t_list;

	new_t_list = malloc(sizeof(*new_t_list));
	if (new_t_list != NULL)
	{
		new_t_list->content = content;
		new_t_list->next = NULL;
		return (new_t_list);
	}
	else
		return (NULL);
}
