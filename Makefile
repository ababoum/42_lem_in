# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marwa <marwa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 17:28:23 by marwa             #+#    #+#              #
#    Updated: 2023/03/08 17:52:23 by marwa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS_COLOR		=		\033[34m
OK_COLOR		=		\033[32m
EOC				=		\033[37;0m
ECHO			=		echo
MKDIR			=		mkdir

NAME			=		lem-in

CC				=		gcc
CFLAGS			=		$(INC) -Wall -Werror -Wextra

SRCDIR			=		srcs
OBJDIR			=		objs/
BINDIR			=		.
INCLUDESDIR		=		includes/

LIBFTDIR		=		libft
LIBFT			=		$(LIBFTDIR)/libft.a

VPATH			=		$(INCLUDESDIR) \
						$(SRCDIR) \
			 			$(SRCDIR)/queue
INCLUDES		=		lem_in.h
SRCS			=		get_next_line.c main.c pathfinder.c rooms.c utils.c
SRCS			+=		queue.c initialize.c is_empty.c

OBJECTS			=		$(addprefix $(OBJDIR), $(SRCS:.c=.o))

INC 			=		-I $(INCLUDESDIR) -I $(LIBFTDIR)

LFLAGS			=		-L $(LIBFTDIR) -lft -ltermcap

all:
	@$(MAKE) -C $(LIBFTDIR)
	@$(ECHO) "$(FLAGS_COLOR)Compiling with flags $(CFLAGS) $(EOC)"
	@$(MAKE) $(BINDIR)/$(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(BINDIR)/$(NAME): $(LIBFT) $(OBJDIR) $(OBJECTS)
	@$(CC) -o $@ $(OBJECTS) $(CFLAGS) $(LFLAGS)
	@$(ECHO) "$(OK_COLOR)$(NAME) linked with success !$(EOC)"

$(OBJDIR):
	@$(MKDIR) $@

$(OBJDIR)%.o: $(SRC_DIR)%.c $(INCLUDES)
	@$(CC) -c $< -o $@ $(CFLAGS)
	@$(ECHO) "${COMP_COLOR}$< ${EOC}"

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(RM) $(OBJECTS)
	@$(RM) -r $(OBJDIR) && $(ECHO) "${OK_COLOR}Successfully cleaned $(NAME) objects files ${EOC}"

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(RM) $(BINDIR)/$(NAME)  && $(ECHO) "${OK_COLOR}Successfully cleaned $(NAME) ${EOC}"

re: fclean all



