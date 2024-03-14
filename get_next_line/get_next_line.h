/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eny-fiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:18:57 by eny-fiti          #+#    #+#             */
/*   Updated: 2024/03/13 13:32:47 by eny-fiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_substr(char	*s, unsigned int start, size_t len);
char    *get_next_line(int fd);
char	*ft_strchr(char	*s, int c);
int	ft_strlen(char	*s);
char	*ft_strjoin(char	*s1, char *s2);
char	*ft_strdup(char	*s);
#endif
