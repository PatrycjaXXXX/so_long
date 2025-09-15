# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/30 14:44:28 by psmolich          #+#    #+#              #
#    Updated: 2025/09/08 05:30:31 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
.PHONY: all basic bonus clean effi fclean re
.DEFAULT_GOAL := basic

PUSHSWAP := push_swap
CHECKER := checker

LIB := libft/libft.a

SRCS_PUSHSWAP := MANDATORY/push_swap.c \
					MANDATORY/arguments.c \
					MANDATORY/instructions.c \
					MANDATORY/sorting.c \
					MANDATORY/movetop.c \
					MANDATORY/lis_utils.c \
					MANDATORY/LIST/ft_lstaddback.c \
					MANDATORY/LIST/ft_lstaddfront.c \
					MANDATORY/LIST/ft_lstfree.c \
					MANDATORY/LIST/ft_lstissorted_as.c \
					MANDATORY/LIST/ft_lstissorted_des.c \
					MANDATORY/LIST/ft_lstlargest.c \
					MANDATORY/LIST/ft_lstlast.c \
					MANDATORY/LIST/ft_lstnew.c \
					MANDATORY/LIST/ft_lstindex.c \
					MANDATORY/LIST/ft_lstprint.c \
					MANDATORY/LIST/ft_lstsize.c \
					MANDATORY/LIST/ft_lstsmallest.c


SRCS_CHECKER := BONUS/checker.c \
					BONUS/arguments.c \
					BONUS/instructions.c \
# 					BONUS/t_list.c

CC := cc
CFLAGS := -Wall -Wextra -Werror

# Efficiency test
N ?= 5
TESTS ?= 100
RANGE ?= $(shell expr $(N) - 1)

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m
BLUE = \033[0;34m
RESET = \033[0m

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

rep:
	rm -f push_swap
	make basic

# effi:
# 	@echo "$(YELLOW)   Testing push_swap efficiency with N=$(N) up to $(TESTS) tests...$(RESET)"
# 	@> instr.txt
# 	@i=0; \
# 	while [ $$i -lt $(TESTS) ]; do \
# 	ARG=$$(shuf -i 0-1000 -n $(N) | xargs); \
# 	COUNT=$$(./push_swap $$ARG | wc -l); \
# 	echo $$COUNT >> instr.txt; \
# 	i=$$((i+1)); \
# 	done
# 	@MIN=$$(sort -n instr.txt | head -1); \
# 	MAX=$$(sort -n instr.txt | tail -1); \
# 	AVG=$$(awk '{ total += $$1; count++ } END { if (count > 0) printf("%.2f", total/count); }' instr.txt); \
# 	echo "$(GREEN)   Average : $$AVG$(RESET)"; \
# 	echo "$(BLUE)   Minimum : $$MIN$(RESET)"; \
# 	echo "$(RED)   Maximum : $$MAX$(RESET)";
# 	@rm -f instr.txt

effi:
	@echo "$(YELLOW)   Testing push_swap efficiency with N=$(N) up to $(TESTS) tests...$(RESET)"
	@> instr.txt
	@i=0; \
	while [ $$i -lt $(TESTS) ]; do \
		ARG=$$(shuf -i 0-$(RANGE) -n $(N) | xargs); \
		COUNT=$$(./push_swap $$ARG | wc -l); \
		echo "$$COUNT|$$ARG" >> instr.txt; \
		i=$$((i+1)); \
	done
	@MIN_LINE=$$(sort -n -t"|" -k1 instr.txt | head -1); \
	MAX_LINE=$$(sort -n -t"|" -k1 instr.txt | tail -1); \
	AVG=$$(awk -F"|" '{ total += $$1; count++ } END { if (count > 0) printf("%.2f", total/count); }' instr.txt); \
	MIN=$$(echo $$MIN_LINE | cut -d"|" -f1); \
	MAX=$$(echo $$MAX_LINE | cut -d"|" -f1); \
	MIN_ARG=$$(echo $$MIN_LINE | cut -d"|" -f2-); \
	MAX_ARG=$$(echo $$MAX_LINE | cut -d"|" -f2-); \
	echo "$(GREEN)   Average : $$AVG$(RESET)"; \
	echo "$(BLUE)   Minimum : $$MIN$(RESET) with ARG=$$MIN_ARG"; \
	echo "$(RED)   Maximum : $$MAX$(RESET) with ARG=$$MAX_ARG";
	@rm -f instr.txt

sort:
	@for N in $$(seq 4 20) 30 40 50 60 70 80 90 100; do \
		echo "$(YELLOW)   Testing N=$$N ...$(RESET)"; \
		> instr.txt; \
		i=0; \
		while [ $$i -lt 50 ]; do \
			ARG=$$(shuf -i 0-$(RANGE) -n $$N | xargs); \
			COUNT=$$(./push_swap $$ARG | wc -l); \
			echo "$$COUNT|$$ARG" >> instr.txt; \
			i=$$((i+1)); \
		done; \
		MAX_LINE=$$(sort -n -t"|" -k1 instr.txt | tail -1); \
		MAX=$$(echo $$MAX_LINE | cut -d"|" -f1); \
		MAX_ARG=$$(echo $$MAX_LINE | cut -d"|" -f2-); \
		echo "$(RED)   MAX for N=$$N : $$MAX$(RESET) with ARG=$$MAX_ARG"; \
		rm -f instr.txt; \
	done
