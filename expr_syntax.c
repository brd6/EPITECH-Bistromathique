/*
** expr_syntax.c for expr_syntax in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Oct 27 14:20:59 2015 berdrigue bongolo-beto
** Last update Sun Nov  1 12:11:41 2015 berdrigue bongolo-beto
*/

#include "bistromathique.h"
#include "my.h"

int	check_op_priority(char op1, char op2, char *ops)
{
  int	pos1;
  int	pos2;

  pos1 = my_get_char_pos(ops, op1);
  pos2 = my_get_char_pos(ops, op2);
  return (pos1 >= pos2);
}

int	is_ops(char *ops, char c, int flag)
{
  if (flag == 0)
    return (c == ops[2] || c == ops[3]);
  else if (flag == 1)
    return (c == ops[4] || c == ops[5] || c == ops[6]);
}

void	get_nbr_with_sign(t_bistro *bistro, int *i, int *j, char *output)
{
  if ((*i == 0 || bistro->token[*i - 1] == bistro->ops[0] ||
       is_ops(bistro->ops, bistro->token[*i - 1], 1)) &&
      is_ops(bistro->ops, bistro->token[*i], 0) &&
      my_get_char_pos(bistro->base, bistro->token[*i + 1]) != -1)
    {
      if (bistro->token[*i] != bistro->ops[2])
	{
	  output[*j] = bistro->token[*i];
	  *j = *j + 1;
	}
      *i = *i + 1;
    }
  if (my_get_char_pos(bistro->base, bistro->token[*i]) != -1)
    {
      get_correct_nbr(bistro, i, j, output);
      output[*j] = ' ';
      *j = *j + 1;
    }
}

int	check_parenthesis(char *expr, char *ops)
{
  int	i;
  int	par_left;
  int	par_right;

  i = 0;
  par_left = 0;
  par_right = 0;
  while (expr[i])
    {
      if (expr[i] == ops[0])
	par_left = par_left + 1;
      if (expr[i] == ops[1])
	par_right = par_right + 1;
      i = i + 1;
    }
  return (par_left == par_right);
}

int	expr_syntax(char *expr, char *ops, char *base)
{
  int		i;
  char		*base_ops;

  i = 0;
  base_ops = my_strcat(my_strdup(base), ops);
  while (expr[i])
    {
      if (my_get_char_pos(base_ops, expr[i]) == -1)
	return (0);
      if (expr[i + 1] == ops[0] && my_get_char_pos(ops, expr[i]) == -1)
	return (0);
      if ((expr[i] == ops[5] || expr[i] == ops[6]) && expr[i + 1] == base[0])
	return (0);
      if (my_get_char_pos(&ops[4], expr[i]) != -1)
	{
	  if (expr[i] == expr[i + 1])
	    return (0);
	  if (my_get_char_pos(base, expr[i - 1]) == -1 && expr[i - 1] != ops[1])
	    return (0);
	}
      i = i + 1;
    }
  return (check_parenthesis(expr, ops));
}
