NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror


LIBFT_DIR	= libs/Libft
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

LIBFT		= $(LIBFT_DIR)/libft.a

INCLUDES	= -I$(LIBFT_DIR) -I$(INCLUDE_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(obj)
	@$(CC) $(CFLAGS) $(obj) $(LIBFT) $(LFLAGS) -o $(NAME)
	@echo "$(NAME) compiled successfully!"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(obj): | $(obj_DIR)

$(obj_DIR):
	@mkdir -p $(obj_DIR)

$(obj_DIR)/%.o: $(src_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(obj_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re