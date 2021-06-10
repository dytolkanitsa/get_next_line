/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:12:44 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/12 16:33:19 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// # define BUFFER_SIZE 10
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_gl
{
	int			bytes_read;
	char		*linebreak;
	char		*buff;
	char		*temp;
}	t_gl;

char	*ft_strchr(char const *string, int symbol);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);

#endif