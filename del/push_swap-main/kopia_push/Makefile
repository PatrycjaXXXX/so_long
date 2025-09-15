# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 13:20:43 by psmolich          #+#    #+#              #
#    Updated: 2025/08/10 06:50:28 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
.PHONY: all basic bonus clean fclean re

PUSHSWAP := push_swap
CHECKER := checker

LIB := libft/libft.a

SRCS_PUSHSWAP := push_swap.c arguments.c instructions.c sorting.c radix.c
SRCS_CHECKER := checker.c arguments.c instructions.c

LST_UTILS := lst_int/ft_lstadd_back.c \
			lst_int/ft_lstadd_front.c \
			lst_int/ft_lstcopy.c \
			lst_int/ft_lstempty.c \
			lst_int/ft_lstfree.c \
			lst_int/ft_lstissorted_as.c \
			lst_int/ft_lstissorted_des.c \
			lst_int/ft_lstlast.c \
			lst_int/ft_lstnew.c \
			lst_int/ft_lstprint.c \
			lst_int/ft_lstsize.c \
			lst_int/ft_lstlargest.c \
			lst_int/ft_lstsmallest.c

CC := cc
CFLAGS := -Wall -Wextra -Werror

basic: $(PUSHSWAP)

bonus: $(CHECKER) 

all: $(PUSHSWAP) $(CHECKER) 

$(PUSHSWAP): $(LIB)
	$(CC) $(CFLAGS) -o $(PUSHSWAP) $(SRCS_PUSHSWAP) $(LST_UTILS) $(LIB)

$(CHECKER): $(LIB)
	$(CC) $(CFLAGS) -o $(CHECKER) $(SRCS_CHECKER) $(LST_UTILS) $(LIB)

$(LIB):
	make -C libft/

clean:
	make clean -C libft/

fclean: clean
	rm -f $(PUSHSWAP)
	rm -f $(CHECKER)
	make fclean -C libft/

re: fclean all