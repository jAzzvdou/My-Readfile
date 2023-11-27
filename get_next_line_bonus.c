/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:09:37 by jazevedo          #+#    #+#             */
/*   Updated: 2023/11/27 17:10:07 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*cutter(char *wardrobe)
{
	char	*single_line;
	size_t	end;

	end = 0;
	while (wardrobe[end] && wardrobe[end] != '\n')
		end++;
	while (wardrobe[end] == '\n')
		end++;
	single_line = malloc(end + 1);
	if (single_line == NULL)
		return (NULL);
	single_line[end] = '\0';
	while (single_line--)
		single_line[end] = wardrobe[end];
	return (single_line);
}

char	*remover(char *wardrobe)
{
	char	*new_wardrobe;
	size_t	end;

	end = 0;
	while (wardrobe[end] && wardrobe[end] != '\n')
		end++;
	while (wardrobe[end] == '\n')
		end++;
	new_wardrobe = ft_strdup(wardrobe + end);
	if (new_wardrobe == NULL)
		return (NULL);
	return (new_wardrobe);
}

char	*get_next_line(int fd)
{
	static char	*wardrobe[256];
	char		buffer[BUFFER_SIZE + 1];
	char		*single_line;
	size_t		bytes;

	wardrobe = NULL;
	bytes = BUFFER_SIZE;
	while (bytes == BUFFER_SIZE)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == (size_t)(-1))
			return (NULL);
		buffer[bytes] = '\0';
		wardrobe = ft_strjoin(wardrobe, buffer);
		if (ft_strchr(wardrobe, '\n') != NULL)
			break ;
	}
	single_line = cutter(wardrobe);
	if (single_line[0] == '\0')
	{
		free(single_line);
		return (NULL);
	}
	wardrobe = remover(wardrobe);
	return (single_line);
}
