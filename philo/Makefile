NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror


src_DIR	= src
obj_DIR	= obj
INCLUDE_DIR	= includes
LFLAGS = -lreadline

src		= src/main.c \
		src/parsing.c \
		src/init.c


obj		= obj/main.o \
		obj/parsing.o \
		obj/init.o

INCLUDES	= -I$(INCLUDE_DIR)

all: $(NAME)

$(NAME): $(obj)
	@$(CC) $(CFLAGS) $(obj) $(LFLAGS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

$(obj): | $(obj_DIR)

$(obj_DIR):
	@mkdir -p $(obj_DIR)

$(obj_DIR)/%.o: $(src_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(obj_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re