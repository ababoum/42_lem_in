F_NONE			= \033[37;0m
F_BOLD			= \033[1m
F_ORANGE		= \033[38m
F_RED			= \033[31m
F_YELLOW		= \033[33m
F_GREEN			= \033[32m
F_CYAN			= \033[36m
F_BLUE			= \033[34m

CC			= @gcc

CFLAGS		= -Wall -Wextra -Werror -g

NAME		= lem-in

SRCS		= srcs/main.c \
				srcs/rooms.c \
				srcs/utils.c \
				srcs/get_next_line.c

INCLUDES	= inc/lem_in.h

OBJ			= $(SRCS:.c=.o)
LIBFT		= libft/libft.a
LIBFT_PATH	= libft/

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_PATH) -lft
	@echo "$(F_GREEN)$(F_BOLD) $(NAME) executable is compiled and ready.$(F_NONE)"


clean:
	@rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean
	@echo "$(F_CYAN)$(F_BOLD) .o files successfully deleted.$(F_NONE)"

fclean:
	@rm -rf $(OBJ)
	@echo "$(F_CYAN)$(F_BOLD) .o files successfully deleted.$(F_NONE)"
	@rm -rf $(NAME)
	@echo "$(F_CYAN)$(F_BOLD) $(NAME) executable(s) successfully deleted.$(F_NONE)"
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
