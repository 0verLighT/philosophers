CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address,thread
NAME = philo
INCLUDES = -Iincludes
BUILD_DIR = .build

SRC = main.c utils.c parser.c

SRCS = \
	$(addprefix src/, $(SRC)) \

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

$(BUILD_DIR):
	@mkdir -p $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

re: fclean
	$(MAKE) all

clean:
	rm -rf .build/

fclean: clean
	rm -f $(NAME)

.PHONY: all re fclean clean
