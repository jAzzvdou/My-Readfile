#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif //BUFFER_SIZE

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

//UTILS
size_t	my_strlen(const char *str);
char	*my_strchr(const char *s, int c);
char	*my_strdup(const char *s);
char	*my_strjoin(char *s1, char *s2);

#endif //GNL
