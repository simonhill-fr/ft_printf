/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 21:49:08 by shill             #+#    #+#             */
/*   Updated: 2016/02/01 21:49:10 by shill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		line_length(char *s)
{
	int				i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int		mem_content(char **line, char **mem_line, int len)
{
	char			*tmp;

	if (!(*line = ft_strndup(*mem_line, len)))
		return (-1);
	if (!(tmp = ft_strdup(ft_strchr(*mem_line, '\n'))))
		return (-1);
	if (!(*mem_line = ft_strdup(tmp + 1)))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}

static int		mem_and_buf(char **line, char **mem_line, int n, char *buf)
{
	char			*tmp;

	if (!(*line = ft_strnjoin(*mem_line, buf, n)))
		return (-1);
	if (!(tmp = *mem_line))
		return (-1);
	if (!(*mem_line = ft_strdup(ft_strchr(buf, '\n') + 1)))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}

static int		ft_read(int const fd, char **line, char **mem_line)
{
	int				n;
	char			buf[BUFF_SIZE + 1];
	int				len;
	char			*tmp;

	tmp = NULL;
	while ((n = read(fd, buf, BUFF_SIZE)))
	{
		if (n == -1)
			return (-1);
		buf[n] = '\0';
		len = line_length(buf);
		if (len >= 0)
			return (mem_and_buf(line, mem_line, len, &buf[0]));
		if (len == -1)
		{
			tmp = *mem_line;
			if (!(*mem_line = ft_strnjoin(*mem_line, buf, n)))
				return (-1);
			ft_strdel(&tmp);
		}
	}
	return (5);
}

int				get_next_line(int const fd, char **line)
{
	static char		*mem_line[256];
	int				len;
	int				n;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd > 255)
		return (-1);
	if (!mem_line[fd])
	{
		if (!(mem_line[fd] = ft_strnew(0)))
			return (-1);
	}
	*line = NULL;
	if ((len = line_length(mem_line[fd])) >= 0)
		return (mem_content(line, &mem_line[fd], len));
	if ((n = ft_read(fd, line, &mem_line[fd])) && (n != 5))
		return (n);
	if ((ft_strcmp(mem_line[fd], "") != 0))
	{
		*line = ft_strdup(mem_line[fd]);
		mem_line[fd] = "";
		return (1);
	}
	return (0);
}
