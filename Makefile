# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:00:01 by jazevedo          #+#    #+#              #
#    Updated: 2023/11/27 17:02:28 by jazevedo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line.a

SRCS	=	get_next_line.c       \
		get_next_line_utils.c

SRCS_BONUS 	=	get_next_line_bonus.c \
			get_next_line_utils.c

		
OBJS	=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Werror -Wextra

RM	=	rm -rf 

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) -c $<

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS) $(OBJS_BONUS)
		ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

.PHONY: all clean fclean re bonus
