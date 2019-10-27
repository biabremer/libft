/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 16:06:41 by bbremer        #+#    #+#                */
/*   Updated: 2019/10/27 13:40:50 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t ih;
	size_t in;

	if (*needle == '\0')
		return ((char*)haystack);
	ih = 0;
	while (haystack[ih] != '\0')
	{
		in = 0;
		while (needle[in] == haystack[ih + in])
		{
			if (needle[in + 1] == '\0')
				return ((char*)haystack + ih);
			in++;
		}
		ih++;
	}
	return (0);
}
