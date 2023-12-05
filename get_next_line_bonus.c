/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:37:42 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/05 11:54:30 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	cleaner(char **s)
{
	free(*s);
	*s = NULL;
}

char	*new_box(char **box, int newline)
{
	char	*temporary;
	int		i;

	i = ft_strlen(*box) - newline;
	temporary = strdup_n(*box + newline, i);
	cleaner(box);
	*box = temporary;
	return (*box);
}

char	*result(char **box, int newline, int readed_bytes)
{
	char	*single_line;

	if ((readed_bytes < 1 && !*box) || newline == -2)
	{
		if (*box)
			return (*box);
		return (NULL);
	}
	single_line = NULL;
	if (newline == -1)
		newline = ft_strlen(*box);
	else
		newline++;
	single_line = strdup_n(*box, newline);
	if (newline == ft_strlen(*box))
		cleaner(box);
	else
		*box = new_box(box, newline);
	return (single_line);
}

char	*get_next_line(int fd)
{
	static char	*box[1024];
	char		*str_buffer;
	int			readed_bytes;
	int			newline;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1024)
		return (NULL);
	str_buffer = NULL;
	readed_bytes = 0;
	newline = strchr_with_key(0, box[fd], '\n');
	while (newline == -1 && newline != -2)
	{
		str_buffer = bzero_malloc(BUFFER_SIZE + 1);
		if (!str_buffer)
			return (NULL);
		readed_bytes = read(fd, str_buffer, BUFFER_SIZE);
		if (readed_bytes < 1)
			break ;
		box[fd] = join_n(box[fd], str_buffer, readed_bytes);
		newline = strchr_with_key(1, box[fd], '\n');
		cleaner(&str_buffer);
	}
	cleaner(&str_buffer);
	return (result(&box[fd], newline, readed_bytes));
}
