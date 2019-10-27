/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 17:29:05 by bbremer        #+#    #+#                */
/*   Updated: 2019/10/27 13:40:50 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fresh;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	fresh = ft_strdup((const char*)s);
	if (fresh == NULL)
		return (NULL);
	while (fresh[i] != '\0')
	{
		fresh[i] = f((unsigned char)i, fresh[i]);
		i++;
	}
	return (fresh);
}
