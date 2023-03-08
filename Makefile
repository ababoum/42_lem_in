# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marwa <marwa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 17:28:23 by marwa             #+#    #+#              #
#    Updated: 2023/03/08 23:12:36 by marwa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS_COLOR		=		\033[34m
OK_COLOR		=		\033[32m
EOC				=		\033[37;0m
ECHO			=		echo
MKDIR			=		mkdir

NAME			=		lem-in

CC				=		gcc
CFLAGS			=		$(INC) -Wall -Wextra

SRCDIR			=		srcs
OBJDIR			=		objs/
BINDIR			=		.
INCLUDESDIR		=		includes/

LIBFTDIR		=		libft
LIBFT			=		$(LIBFTDIR)/libft.a

VPATH			=		$(INCLUDESDIR) \
						$(SRCDIR) \
			 			$(SRCDIR)/algorithm \
			 			$(SRCDIR)/queue \
			 			$(SRCDIR)/rooms \
			 			$(SRCDIR)/utils

INCLUDES		=		lem_in.h

#############################
# 			Main			#
#############################
SRCS			=		main.c
#############################
# 			Algorithm		#
#############################
SRCS			+=		add_path.c pathfinder.c create_path.c print_path.c print_all_paths.c
#############################
# 			Queue			#
#############################
SRCS			+=		initialize.c is_empty.c push.c pop.c
#############################
# 			Rooms			#
#############################
SRCS			+=		new_room.c split_room_line.c get_room_id.c split_link_line.c free_room.c print_room.c duplicate_room.c
#############################
# 			Utils			#
#############################
SRCS			+=		ft_is_numeric.c ft_is_signed_numeric.c  tab_len.c free_tab.c trim_new_line.c get_next_line.c
						

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



