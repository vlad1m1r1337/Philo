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

$(OBJDIR):
	$(shell mkdir -p $(dir $(OBJS)))

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

clean:
	rm -r $(OBJDIR)

fclean: clean
	rm -r $(NAME)

re: fclean all

PHONY: all clean fclean re