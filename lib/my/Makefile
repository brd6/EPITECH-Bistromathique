##
## Makefile for libmy in /home/bongol_b/rendu/Piscine_C_workshoplib/lib/my
## 
## Made by berdrigue bongolo-beto
## Login   <bongol_b@epitech.net>
## 
## Started on  Fri Oct 16 01:07:43 2015 berdrigue bongolo-beto
## Last update Fri Oct 16 01:14:11 2015 berdrigue bongolo-beto
##

CC	= gcc

RM	= rm -Rf

AR	= ar cr

LDFLAGS	= -L. -lmy

CFLAGS	= -Iinclude

NAME	= libmy.a

MY_H	= my.h

SRCS	= $(shell find -type f -name "*.c")

OBJS	= $(SRCS:.c=.o)

LIBCPY	= cp -f $(NAME) ../

all: $(NAME)
	@$(LIBCPY)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(OBJS) :
	@$(CC) -c $(SRCS)
clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re	: fclean all

.PHONY: clean, mrproper, re, all, fclean
