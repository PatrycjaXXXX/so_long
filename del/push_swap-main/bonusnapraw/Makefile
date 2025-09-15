# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 11:42:15 by psmolich          #+#    #+#              #
#    Updated: 2025/09/12 12:01:15 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all basic bonus clean effi fclean re
.DEFAULT_GOAL := basic

CC := cc
CFLAGS := -Wall -Wextra -Werror -g

PUSHSWAP := push_swap
CHECKER := checker

LIB := libft/libft.a

LINKED_LIST := LIST/ft_lstaddback.c \
					LIST/ft_lstaddfront.c \
					LIST/ft_lstfree.c \
					LIST/ft_lstissorted_as.c \
					LIST/ft_lstissorted_des.c \
					LIST/ft_lstlargest.c \
					LIST/ft_lstlast.c \
					LIST/ft_lstnew.c \
					LIST/ft_lstindex.c \
					LIST/ft_lstprint.c \
					LIST/ft_lstsize.c \
					LIST/ft_lstsmallest.c

SRCS_PUSHSWAP := push_swap.c \
					arguments.c \
					instructions.c \
					sorting.c \
					movetop.c \
					lis_utils.c \
					$(LINKED_LIST)

SRCS_CHECKER := checker_bonus.c \
					arguments.c \
					instructions.c \
					$(LINKED_LIST)

all: $(PUSHSWAP) $(CHECKER)

basic: $(PUSHSWAP)

bonus: $(CHECKER)

$(PUSHSWAP): $(LIB)
	$(CC) $(CFLAGS) -o $(PUSHSWAP) $(SRCS_PUSHSWAP) $(LIB)

$(CHECKER): $(LIB)
	$(CC) $(CFLAGS) -o $(CHECKER) $(SRCS_CHECKER) $(LIB)

$(LIB):
	make -C libft/

clean:
	make clean -C libft/

fclean: clean
	rm -f $(PUSHSWAP)
	rm -f $(CHECKER)
	make fclean -C libft/

re: fclean all

# TESTS=100
# SIZES="4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 30 40 50 60 70 80 90 100 200 300 400 500"
# MAX_INT=2147483647

# for N in $SIZES; do
#     max=0
#     for ((i=0; i<TESTS; i++)); do
#         args=$(shuf -i 0-$MAX_INT -n $N | xargs)

#         ops=$(./push_swap $args | wc -l)

#         if [ "$ops" -gt "$max" ]; then
#             max=$ops
#         fi
#     done
#     echo "$N -> max $max"
# done