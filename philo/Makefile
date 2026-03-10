CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=thread
NAME = philo
INCLUDES = -Iincludes

SRC = main.c utils.c parser.c ft_philo.c

SRCS = \
	$(addprefix src/, $(SRC)) \

OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

re: fclean
	$(MAKE) all

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all re fclean clean
