/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 15:17:48 by bbremer        #+#    #+#                */
/*   Updated: 2019/10/27 13:40:50 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	f;

	i = 0;
	if (!s)
		return (NULL);
	f = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	while (s[f] == ' ' || s[f] == '\n' || s[f] == '\t')
		f--;
	return (ft_strsub(s, i, f - i + 1));
}
