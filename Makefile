NAME=philo

SRCDIR = src/
OBJDIR = obj/

SRCS = $(wildcard **/*.c)
OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread  #-fsanitize=thread
LIBS = -lpthread
RM = rm -rf

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(OBJDIR)%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	$(shell mkdir -p $(dir $(OBJS)))

$(NAME): $(OBJDIR) $(OBJS)
	@$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	@echo "${GREEN}>>> RDY <<<${RESET}"

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re