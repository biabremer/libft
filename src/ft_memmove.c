/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 10:02:45 by bbremer        #+#    #+#                */
/*   Updated: 2019/10/27 13:40:50 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*x;
	const unsigned char	*y;

	x = (unsigned char*)dst;
	y = (unsigned char*)src;
	if (y < x)
	{
		x += len;
		y += len;
		while (len > 0)
		{
			len--;
			x--;
			y--;
			*x = *y;
		}
	}
	else
		while (len > 0)
		{
			len--;
			*x++ = *y++;
		}
	return (dst);
}
