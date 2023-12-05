/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:40:05 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/05 11:57:20 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*bzero_malloc(int buffersize)
{
	char	*final;
	int		i;

	final = (char *)malloc(buffersize);
	if (!final)
		return (NULL);
	i = -1;
	while (++i < buffersize)
		final[i] = 0;
	return (final);
}

int	strchr_with_key(int key, char *box, char c)
{
	int	i;

	if (key == 1 && !box)
		return (-2);
	i = -1;
	while (box && box[++i])
	{
		if (box[i] == c)
			return (i);
	}
	return (-1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s && s[i])
		i++;
	return (i);
}

char	*join_n(char *box, char *str_buffer, int newline)
{
	char	*final;
	int		i;
	int		ii;

	if (str_buffer[0] == '\0')
		return (NULL);
	final = malloc(sizeof(char) * (ft_strlen(box) + newline + 1));
	if (!final)
		return (NULL);
	i = 0;
	while (box && box[i])
	{
		final[i] = box[i];
		i++;
	}
	ii = 0;
	while (str_buffer && str_buffer[ii] && ii < newline)
		final[i++] = str_buffer[ii++];
	final[i] = '\0';
	if (box)
		cleaner(&box);
	return (final);
}

char	*strdup_n(char *box, int newline)
{
	char	*final;
	int		i;

	final = malloc(sizeof(char) * (newline + 1));
	if (!final)
		return (NULL);
	i = -1;
	while (box && box[++i] && i < newline)
		final[i] = box[i];
	final[i] = '\0';
	return (final);
}
