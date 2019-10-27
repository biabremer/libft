/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 14:02:26 by bbremer        #+#    #+#                */
/*   Updated: 2019/10/27 13:40:50 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_words(char const *s, char c)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[0] != c)
		{
			nb++;
			i++;
		}
		if (s[i - 1] == c && s[i] != c)
		{
			nb++;
			i++;
		}
		i++;
	}
	return (nb);
}

static int		ft_strsize(char const *s, char c, int start)
{
	int		len;

	len = 0;
	while (s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

static char		**ft_fillarrays(char **as, char const *s, char c)
{
	int		y;
	int		x;
	int		b;

	b = 0;
	y = 0;
	x = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		if (s[x] == '\0')
			break ;
		b = 0;
		while (s[x] != c && s[x] != '\0')
		{
			as[y][b] = s[x];
			x++;
			b++;
		}
		as[y][b] = '\0';
		y++;
	}
	as[y] = NULL;
	return (as);
}

static char		**ft_mallocarray(char const *s, char **as, char c)
{
	int i;
	int y;

	y = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while ((s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
		{
			(as[y++] = (char*)malloc((ft_strsize(s, c, i) + 1)));
			i++;
		}
		i++;
	}
	return (as);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**as;
	int		nb;

	if (s == NULL)
		return (0);
	nb = ft_words(s, c);
	as = (char**)malloc((sizeof(char*) * (ft_words(s, c) + 1)));
	if (as == NULL)
		return (NULL);
	ft_mallocarray(s, as, c);
	if (as == NULL)
		return (NULL);
	ft_fillarrays(as, s, c);
	return (as);
}
