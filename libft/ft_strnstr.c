/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerdoga <seerdoga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:37:28 by seerdoga          #+#    #+#             */
/*   Updated: 2024/10/28 15:44:40 by seerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	i = 0;
	if (needle_len == 0)
	{
		return ((char *)haystack);
	}
	if (len == 0)
	{
		return (NULL);
	}
	while (haystack[i] != '\0' && i + needle_len <= len)
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
		{
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
