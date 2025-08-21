NAME = do-op
SRCS = ft_atoi.c ft_op.c main.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc
INCS = do-op.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
