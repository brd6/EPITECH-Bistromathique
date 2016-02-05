/*
** stack_pop.c for my_stack_pop in /home/bongol_b/rendu/Piscine_C_evalexpr
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Oct 25 16:14:46 2015 berdrigue bongolo-beto
** Last update Fri Oct 30 10:16:57 2015 berdrigue bongolo-beto
*/

#include <stdlib.h>
#include "../../include/mylist.h"

void	*stack_pop(t_list **stack)
{
  t_list	*next;
  void		*data;

  if (*stack == NULL)
    return (NULL);
  if (my_list_size(*stack) == 0)
    return (NULL);
  next = (*stack)->next;
  data = (*stack)->data;
  *stack = next;
  //free(next);
  return (data);
}
