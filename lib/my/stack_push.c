/*
** stack_push.c for my_stack_push in /home/bongol_b/rendu/Piscine_C_evalexpr
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Oct 25 16:15:54 2015 berdrigue bongolo-beto
** Last update Fri Oct 30 09:53:58 2015 berdrigue bongolo-beto
*/


#include <stdlib.h>
#include "../../include/mylist.h"

int		stack_push(t_list **stack, void *data)
{
  t_list        *prec;
  int		i;

  i = 0;
  prec = (t_list *)malloc(sizeof(*prec));
  if (my_list_size(*stack) == 0)
    {
      prec->data = data;
      prec->next = NULL;
      *stack = prec;
    }
  else
    {
      prec->data = data;
      prec->next = *stack;
      *stack = prec;
    }
  return (1);
}
