/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/29 17:58:12 by bbremer        #+#    #+#                */
/*   Updated: 2019/10/27 13:40:50 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_memdup(void const *content, size_t content_size)
{
	void *temp;

	temp = malloc(sizeof(unsigned char) * content_size);
	if (temp == NULL)
		return (NULL);
	ft_memcpy(temp, content, content_size);
	return (temp);
}
