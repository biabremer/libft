/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 18:56:22 by bbremer        #+#    #+#                */
/*   Updated: 2019/10/27 13:40:50 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	if (*needle == 0)
		return ((char*)haystack);
	i = 0;
	while (*haystack != '\0' && i < len)
	{
		if (*haystack == *needle)
		{
			while (*(haystack + i) == *(needle + i) && len - i)
			{
				i++;
				if (*(needle + i) == '\0')
					return ((char*)haystack);
			}
		}
		len--;
		haystack++;
	}
	return (NULL);
}
