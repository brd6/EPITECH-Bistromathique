/*
** rpn_calc.c for rpn_calc in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Oct 28 18:26:00 2015 berdrigue bongolo-beto
** Last update Sun Nov  1 21:08:28 2015 berdrigue bongolo-beto
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

void	rpn_calc_switch_cond(t_bistro *bistro, t_list **stack, char *token)
{
  char	*n1;
  char	*n2;

  n1 = stack_pop(stack);
  n2 = stack_pop(stack);
  if (token[0] == bistro->ops[2])
    stack_push(stack, infin_add(n1, n2, bistro));
  else if (token[0] == bistro->ops[3])
    stack_push(stack, infin_sub(n2, n1, bistro, 0));
  else if (token[0] == bistro->ops[4])
    stack_push(stack, infin_mult(n1, n2, bistro));
  else if (token[0] == bistro->ops[5])
    stack_push(stack, infin_div(n2, n1, bistro));
  else if (token[0] == bistro->ops[6])
    stack_push(stack, infin_mod(n2, n1, bistro));
}

char		*rpn_calc(char *output, t_bistro *bistro)
{
  char		**tab;
  int		i;
  t_list	*stack;

  tab = my_str_split(output, ' ');
  i = 0;
  stack = NULL;
  while (tab[i])
    {
      if (is_ops(bistro->ops, tab[i][0], 0) &&
	  my_get_char_pos(bistro->base, tab[i][1]) != -1 ||
	  my_get_char_pos(bistro->base, tab[i][0]) != -1)
	stack_push(&stack, tab[i]);
     else
	{
	  if (my_list_size(stack) == 1 && tab[i][0] == bistro->ops[3])
	    stack_push(&stack, my_itoa(my_getnbr(stack_pop(&stack)) * (-1)));
	  if (my_list_size(stack) != 1)
	    rpn_calc_switch_cond(bistro, &stack, tab[i]);
	}
      i = i + 1;
    }
  return (stack_top(stack));
}
