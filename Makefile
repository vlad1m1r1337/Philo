NAME=philo

SRCDIR = src/
OBJDIR = obj/

SRCS = $(wildcard $(SRCDIR)*.c)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)
LIBS = -lpthread

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJS) $(OBJS_DIR)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

clean:
	rm -r $(OBJDIR)

fclean: clean
	rm -r $(NAME)

re: fclean all

PHONY: all clean fclean re