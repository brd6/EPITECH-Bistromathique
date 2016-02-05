/*
** stack_top.c for my_stack_top in /home/bongol_b/rendu/Piscine_C_evalexpr
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Oct 25 16:18:22 2015 berdrigue bongolo-beto
** Last update Thu Oct 29 17:37:32 2015 berdrigue bongolo-beto
*/

#include <stdlib.h>
#include "../../include/mylist.h"

void	*stack_top(t_list *stack)
{
  return (stack != NULL) ? (stack->data) : 0;
}
