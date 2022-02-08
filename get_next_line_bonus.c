/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:04:15 by ddelladi          #+#    #+#             */
/*   Updated: 2022/01/21 17:38:50 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *save_read)
{
	int		i;
	char	*line;

	i = 0;
	while (*(save_read + i) != '\n' && *(save_read + i) != '\0')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	if (save_read[i] == '\n')
		i++;
	ft_strlcpy(line, save_read, i + 1);
	return (line);
}

char	*free_and_check(char *save_read, char *help)
{
	free(help);
	if (save_read)
	{
		if (ft_strlen(save_read) == 0)
			free(save_read);
		else
			return (save_read);
	}
	return (NULL);
}

char	*update(int fd, char *save_read)
{
	char	*help;
	int		bytes;

	bytes = 1;
	help = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!help)
		return (NULL);
	while (!ft_strchr(save_read, '\n') && bytes != 0)
	{
		bytes = read(fd, help, BUFFER_SIZE);
		if (bytes < 1)
		{
			save_read = free_and_check(save_read, help);
			if (save_read)
				return (save_read);
			return (NULL);
		}
		help[bytes] = '\0';
		save_read = ft_strjoin_plus(save_read, help);
	}
	free(help);
	return (save_read);
}

char	*subtract_line(char *save_read)
{
	int		i;
	char	*ret;

	i = 0;
	while (save_read[i] != '\n' && save_read[i] != '\0')
		i++;
	if (save_read[i] == '\0')
	{
		free(save_read);
		return (NULL);
	}
	else
	{
		i++;
		ret = malloc(sizeof(char) * (ft_strlen(save_read) - i + 1));
		ft_strlcpy(ret, &save_read[i], ft_strlen(save_read) - i + 1);
		free(save_read);
		return (ret);
	}
}

char	*get_next_line(int fd)
{
	static char	*save_read[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	save_read[fd] = update(fd, save_read[fd]);
	if (!save_read[fd])
		return (NULL);
	line = get_line(save_read[fd]);
	save_read[fd] = subtract_line(save_read[fd]);
	return (line);
}
