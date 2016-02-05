##
## Makefile for bistromathique in /home/bongol_b/rendu/Piscine_C_bistromathique
## 
## Made by berdrigue bongolo-beto
## Login   <bongol_b@epitech.net>
## 
## Started on  Sun Oct 25 15:46:01 2015 berdrigue bongolo-beto
## Last update Sun Nov  1 20:43:44 2015 berdrigue bongolo-beto
##

CC      = gcc

RM      = rm -Rf

NAME	= calc

SRCS	= main.c \
	eval_expr.c \
	my_utils.c \
	expr_syntax.c \
	expr_to_rpn.c \
	rpn_calc.c \
	infin_add.c \
	infin_sub.c \
	infin_sub_utils.c \
	infin_mult.c \
	infin_div.c \
	infin_mod.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS  = -I./include/

LDFLAGS += -L./lib -lmy

LDFLAGS	+= -W -Wall -Wextra -g


all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJS) :
	@$(CC) -c $(SRCS) $(CFLAGS)

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: clean, mrproper, re, all, fclean
