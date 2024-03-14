/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eny-fiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:18:17 by eny-fiti          #+#    #+#             */
/*   Updated: 2024/03/14 16:29:09 by eny-fiti         ###   ########.fr       */
/*                                                                            */
/* ******************i******************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*line_res(char *str)
{
	int	i;
	char	*res;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == 0 || str[1] == 0)
		return (NULL);
	res = ft_substr(str, (i + 1), (len - i));
	if (*res == 0)
	{
		free(res);
		res = NULL;
	}
	res[i + 1] = '\0';
	return (res);
}

// static char	*line_fin(char *str)
// {
// 	int	i;
// 	char	*res;

// 	i = 0;
// 	while (str[i] && str[i] != '\n')
// 		i++;
// 	res = ft_substr(str, 0, i);
// 	return (res);
// }

static char	*all_line(int fd, char *all, char *buf)
{
	int	i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(all);
			return (NULL);
		}
		else if (i == 0)
			break ;
		buf[i] = '\0';
		if (!all)
			all = ft_strdup("");
		all = ft_strjoin(all, buf);
		if (ft_strchr(buf, '\n'))
				break;
	}
	return (all);
}

char	*get_next_line(int fd)
{
	 static char *right;
	 char *line;
	 char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	 {
		 free(right);
		 free(buf);
		 buf = NULL;
		 right = NULL;
		 return (NULL);
	}
	if (buf == NULL)
		return (NULL);
	line = all_line(fd, right, buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	right = line_res(line);
	return (line);
}

int	main()
{
	int	fd;
	int	i;
	char *line;

	fd = open("f", O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (i < 1)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		i++;
	}
}
