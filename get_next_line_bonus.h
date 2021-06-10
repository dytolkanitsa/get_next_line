/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:56:16 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/12 16:33:17 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define FD 1024

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