/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_countwords.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 18:10:08 by bbremer        #+#    #+#                */
/*   Updated: 2019/10/27 13:40:50 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_countwords(char const *s)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	if (!(ft_isspace(s[0])))
	{
		nb++;
		i++;
	}
	while (s[i] != '\0')
	{
		if ((!(ft_isspace(s[i - 1]))) && (ft_isspace(s[i])))
		{
			nb++;
			i++;
		}
		i++;
	}
	return (nb);
}
