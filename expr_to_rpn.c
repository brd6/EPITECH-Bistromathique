/*
** expr_to_rpn.c for expr_to_rpn in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Oct 27 15:25:30 2015 berdrigue bongolo-beto
** Last update Sun Nov  1 12:11:31 2015 berdrigue bongolo-beto
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

void	rpn_switch_cond(t_list **stack, t_bistro *bistro, char *output, int *j)
{
  int	i;
  char	c;

  c = *((char*)(*stack)->data);
  i = bistro->token_idx;
  if (my_list_size(*stack) == 0)
    stack_push(stack, &bistro->token[i]);
  else if (c == bistro->ops[0])
    stack_push(stack, &bistro->token[i]);
  else if (check_op_priority(bistro->token[i], c, bistro->ops))
    stack_push(stack, &bistro->token[i]);
  else
    {
      output[*j] = *((char*)stack_pop(stack));
      output[*j + 1] = ' ';
      *j = *j + 2;
      stack_push(stack, &bistro->token[i]);
    }
}

void	rpn_parenthesis_cond(t_list **stack, t_bistro *bt, char *output, int *j)
{
  int	i;

  i = bt->token_idx;
  while (*((char*)stack_top(*stack)) != bt->ops[0])
    {
      output[*j] = *((char*)stack_pop(stack));
      output[*j + 1] = ' ';
      *j = *j + 2;
    }
  stack_pop(stack);
}

void	rpn_final_push(t_list **stack, char *output, int *j)
{
  while (*stack && (my_list_size(*stack) != 1))
    {
      output[*j] = *((char*)stack_pop(stack));
      output[*j + 1] = ' ';
      *j = *j + 2;
    }
  output[*j] = 0;
}

char		*expr_to_rpn(t_bistro *bistro, char *output)
{
  t_list	*stack;
  int		i;
  int		j;

  stack = (t_list *)malloc(sizeof(*stack));
  if (stack == NULL)
    return (NULL);
  stack->data = "_";
  stack->next = NULL;
  i = 0;
  j = 0;
  bistro->expr = bistro->token;
  while (bistro->token[i])
    {
      get_nbr_with_sign(bistro, &i, &j, output);
      if (bistro->token[i] == bistro->ops[0])
	stack_push(&stack, &bistro->token[i]);
      else if (my_get_char_pos(&bistro->ops[2], bistro->token[i]) != -1)
	rpn_switch_cond(&stack, bistro, output, &j);
      else if (bistro->token[i] == bistro->ops[1])
	rpn_parenthesis_cond(&stack, bistro, output, &j);
      i = i + 1;
      bistro->token_idx = i;
    }
  rpn_final_push(&stack, output, &j);
}
