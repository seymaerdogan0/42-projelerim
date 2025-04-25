/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerdoga <seerdoga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:48:50 by seerdoga          #+#    #+#             */
/*   Updated: 2024/10/28 14:48:50 by seerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_word_alloc(const char *s, char c)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	ft_free_words(char **words, int i)
{
	while (i >= 0)
	{
		free(words[i]);
		i--;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**words;

	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!words)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			words[i] = ft_word_alloc(s, c);
			if (!words[i])
				return (ft_free_words(words, i - 1), NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	words[i] = NULL;
	return (words);
}
