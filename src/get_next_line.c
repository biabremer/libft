/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:44:22 by bbremer        #+#    #+#                */
/*   Updated: 2019/10/27 13:55:44 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_copyuntil(char *str1, char *str2, char c)
{
	int		len;
	int		i;
	char	*str;

	str = 0;
	len = 0;
	i = 0;
	while (str2[i] != c && str2[i] != '\0')
	{
		i++;
	}
	str2[i] = '\0';
	if (str1 && str2)
	{
		len = ft_strlen(str1) + i;
		str = (char *)malloc(sizeof(*str) * (len + 1));
		if (str == NULL)
			return (NULL);
		ft_strcpy(str, str1);
		ft_strcat(str, str2);
	}
	return (str);
}

int		get_line(char **line, char **leftover, const int fd, int ret)
{
	char	*temp;
	char	buf[BUFF_SIZE + 1];
	char	*next;

	next = NULL;
	while (ret == BUFF_SIZE && !next)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		temp = *line;
		next = ft_strchr(buf, '\n');
		if (!(next))
			*line = ft_strjoin(*line, buf);
		if (!(next))
			ft_strclr(*leftover);
		if (next)
		{
			*line = ft_copyuntil(*line, buf, '\n');
			free(*leftover);
			*leftover = (ft_strdup(&next[1]));
		}
		free(temp);
	}
	return (ret);
}

t_list	*find_file(t_list **begin_list, int fd)
{
	t_list	*temp;

	temp = *begin_list;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	ft_lstadd(begin_list, ft_lstnew("", fd));
	return (*begin_list);
}

int		get_ret(char **line, char **leftover, int fd, char *next)
{
	int		ret;
	char	*tmp;

	ret = 1;
	if (next)
	{
		tmp = *line;
		*line = ft_strsub(*leftover, 0, (next - *leftover));
		free(tmp);
		tmp = *leftover;
		*leftover = ft_strdup(&next[1]);
		free(tmp);
	}
	else
	{
		free(*line);
		*line = ft_strdup(*leftover);
		ret = BUFF_SIZE;
		ret = get_line(line, leftover, fd, ret);
	}
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	char				*next;
	static t_list		*leftovers;
	t_list				*curr;
	int					ret;

	if (fd < 0 || line == NULL || (read(fd, buf, 0) == -1))
		return (-1);
	ret = 1;
	*line = ft_strnew(0);
	curr = find_file(&leftovers, fd);
	next = NULL;
	if (curr->content)
		next = ft_strchr((char*)curr->content, '\n');
	ret = get_ret(line, (char**)&curr->content, fd, next);
	if (ret == 0 && !ft_strlen(*line))
		return (0);
	return (1);
}
