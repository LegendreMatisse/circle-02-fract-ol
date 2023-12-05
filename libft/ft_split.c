/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:52:54 by mlegendr          #+#    #+#             */
/*   Updated: 2023/02/06 15:45:22 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcounter(const char *str, char c)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (*str)
	{
		if (*str != c && check == 0)
		{
			check = 1;
			i++;
		}
		else if (*str == c)
			check = 0;
		str++;
	}
	return (i);
}

static char	*ft_copy(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i[2];
	int		index;
	char	**split;

	if (!s)
		return (0);
	split = malloc((ft_wordcounter(s, c) + 1) * sizeof(char *));
	if (!(split))
		return (0);
	i[0] = 0;
	i[1] = 0;
	index = -1;
	while (i[0] <= ft_strlen(s))
	{
		if (s[i[0]] != c && index < 0)
			index = i[0];
		else if ((s[i[0]] == c || i[0] == ft_strlen(s)) && index >= 0)
		{
			split[i[1]++] = ft_copy(s, index, i[0]);
			index = -1;
		}
		i[0]++;
	}
	split[i[1]] = 0;
	return (split);
}
