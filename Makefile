CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= ./srcs/minishell.c ./utils/ft_split.c ./utils/get_next_line.c ./utils/get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

RM	= rm -f

NAME	= minishell

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lreadline

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
