/*
** eval_expr.c for eval_expr in /home/bongol_b/rendu/Piscine_C_evalexpr
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Oct 21 21:53:12 2015 berdrigue bongolo-beto
** Last update Sun Nov  1 21:09:38 2015 berdrigue bongolo-beto
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

void	debug(char *output, t_bistro *bistro)
{
  if (bistro->debug)
    {
      my_putstr("Expression: ");
      my_putstr(bistro->expr_bak);
      my_putstr("\nExpression nettoye: ");
      my_putstr(bistro->token);
      my_putstr("\nConversion de l'expression...\nExpression: ");
      my_putstr(output);
      my_putchar('\n');
    }
}

char		*eval_expr(char *base, char *ops, char *expr, int debug1)
{
  char		*rpn_output;
  t_bistro	*bistro;
  char		**token;

  bistro = malloc(sizeof(*bistro));
  if (bistro == NULL)
    return (NULL);
  bistro->base = my_strdup(base);
  bistro->ops = my_strdup(ops);
  bistro->expr = my_strdup(expr);
  bistro->debug = debug1;
  bistro->size = my_strlen(expr);
  bistro->token = clean_expr(bistro);
  bistro->expr_bak = bistro->expr;
  rpn_output = malloc(my_strlen(bistro->token)*2);
  expr_to_rpn(bistro, rpn_output);
  debug(rpn_output, bistro);
  return rpn_calc(rpn_output, bistro);
}
