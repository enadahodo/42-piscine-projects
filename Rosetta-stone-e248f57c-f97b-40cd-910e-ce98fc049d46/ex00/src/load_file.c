/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azhuri <azhuri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:00:00 by azhuri            #+#    #+#             */
/*   Updated: 2024/05/18 00:00:00 by azhuri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <fcntl.h>

static void	copy_bytes(char *dst, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		dst[index] = src[index];
		index++;
	}
}

static int	append_chunk(char **content, size_t *size, char *buf, ssize_t count)
{
	char	*tmp;

	tmp = (char *)malloc(*size + count + 1);
	if (tmp == NULL)
	{
		free(*content);
		*content = NULL;
		return (0);
	}
	copy_bytes(tmp, *content, *size);
	copy_bytes(tmp + *size, buf, (size_t)count);
	tmp[*size + count] = '\0';
	free(*content);
	*content = tmp;
	*size += count;
	return (1);
}

static int	read_loop(int fd, char **content, size_t *size)
{
	char	buf[1024];
	ssize_t	count;

	count = read(fd, buf, 1024);
	while (count > 0)
	{
		if (!append_chunk(content, size, buf, count))
			return (-1);
		count = read(fd, buf, 1024);
	}
	if (count < 0)
		return (-1);
	return (0);
}

char	*load_file(const char *path)
{
	int		fd;
	char	*content;
	size_t	size;
	int		status;

	content = NULL;
	size = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	status = read_loop(fd, &content, &size);
	close(fd);
	if (status < 0)
	{
		free(content);
		return (NULL);
	}
	if (content == NULL)
		return (ft_strdup(""));
	return (content);
}
