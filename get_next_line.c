/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:38:02 by jazevedo          #+#    #+#             */
/*   Updated: 2023/11/27 19:58:36 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (end--)
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
	static char	*wardrobe;
	char		buffer[BUFFER_SIZE + 1];
	char		*single_line;
	int		bytes;

	wardrobe = NULL;
	bytes = BUFFER_SIZE;
	while (bytes == BUFFER_SIZE)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
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
