/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:37:23 by mlegendr          #+#    #+#             */
/*   Updated: 2023/02/17 17:27:50 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str_dup;
	size_t	len;

	len = ft_strlen(str);
	str_dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_dup)
		return (NULL);
	ft_strlcpy(str_dup, str, len + 1);
	return (str_dup);
}
