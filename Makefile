NAME=philo

SRCDIR = src/
OBJDIR = obj/

SRCS = $(wildcard $(SRCDIR)*.c)
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread  -fsanitize=thread
LIBS = -lpthread

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

clean:
	rm -r $(OBJDIR)*.o

fclean: clean
	rm -r $(NAME)

re: fclean all

PHONY: all clean fclean re