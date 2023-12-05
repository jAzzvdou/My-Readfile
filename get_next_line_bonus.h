/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:36:58 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/05 11:38:41 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif //Buffer size

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

//UTILS
int		ft_strlen(char *s);
int		strchr_with_key(int key, char *s, char c);
void	cleaner(char **s);
void	*bzero_malloc(int buffersize);
char	*strdup_n(char *box, int newline);
char	*join_n(char *box, char *str_buffer, int newline);

#endif //GNL
