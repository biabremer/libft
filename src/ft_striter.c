/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 14:38:27 by bbremer        #+#    #+#                */
/*   Updated: 2019/10/27 13:40:50 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	if (s == NULL || f == NULL)
		return ;
	while (*s)
		f(s++);
}
