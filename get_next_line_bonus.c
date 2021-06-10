/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:05:11 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/12 16:33:15 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_check_rem(char **line, char **reminders)
{
	char	*linebreak;
	char	*temp;

	linebreak = 0;
	if (*reminders)
	{
		linebreak = ft_strchr(*reminders, '\n');
		if (linebreak)
		{
			*linebreak = '\0';
			*line = ft_strjoin(*reminders, "");
			temp = *reminders;
			*reminders = ft_strjoin(++linebreak, "");
			free(temp);
		}
		else
		{
			*line = ft_strjoin(*reminders, "");
			free(*reminders);
			*reminders = NULL;
		}
	}
	else
		*line = ft_strjoin("", "");
	return (linebreak);
}

static int	if_linebreak(t_gl *gl, char **reminders)
{
	*gl->linebreak = '\0';
	*reminders = ft_strjoin(++gl->linebreak, "");
	if (!(reminders))
		return (-1);
	return (0);
}

static int	init_params_in_cycle(t_gl *gl, int fd)
{
	gl->bytes_read = read(fd, gl->buff, BUFFER_SIZE);
	if (gl->bytes_read == 0 || gl->bytes_read == -1)
		return (0);
	gl->buff[gl->bytes_read] = '\0';
	gl->linebreak = ft_strchr(gl->buff, '\n');
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*reminders[FD];
	char		*temp;
	t_gl		gl;

	gl.buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE < 1 || !line || \
	!gl.buff || (read(fd, gl.buff, 0) < 0))
		return (-1);
	gl.linebreak = ft_check_rem(line, &reminders[fd]);
	while (!gl.linebreak)
	{
		if (!(init_params_in_cycle(&gl, fd)))
			break ;
		if (gl.linebreak)
			if_linebreak(&gl, &reminders[fd]);
		temp = *line;
		*line = ft_strjoin(*line, gl.buff);
		free(temp);
	}
	free(gl.buff);
	if (gl.linebreak)
		return (1);
	return (0);
}
