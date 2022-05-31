/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:07:38 by jhurtado          #+#    #+#             */
/*   Updated: 2022/04/26 10:21:03 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	separator(char c, char charset)
{
	if (charset == c)
	{
		return (1);
	}
	if (c == '\0')
	{
		return (1);
	}
	return (0);
}

int	count_words(char *str, char charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!(separator(str[i], charset)) && separator(str[i + 1], charset))
		{
			words++;
		}
		i++;
	}
	return (words);
}

void	write_word(char *dest, char *str, int i, char charset)
{
	int	j;

	j = 0;
	while (!separator(str[i], charset))
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
}

void	write_split(char **split, char *str, char charset)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (separator(str[i], charset))
		{
			i++;
		}
		else
		{
			j = 0;
			while (!(separator(str[i + j], charset)))
			{
				j++;
			}
			split[word] = malloc(sizeof(char) * (j + 1));
			write_word(split[word], str, i, charset);
			i = i + j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	char	*str;

	str = (char *)s;
	words = count_words(str, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split[words] = NULL;
	write_split(split, str, c);
	return (split);
}
