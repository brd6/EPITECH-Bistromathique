/*
** main.c for bistromathique in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Oct 25 14:46:33 2015 berdrigue bongolo-beto
** Last update Sun Nov  1 21:01:22 2015 berdrigue bongolo-beto
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromathique.h"
#include "my.h"

static void check_base(char *base);
static void check_ops(char *ops);
static char *get_expr(unsigned size);

int		main(int ac, char **av)
{
  char		*expr;
  unsigned int	debug;
  int		expr_ok;

  if (ac < 4)
    {
      my_putstr("Usage : ");
      my_putstr(av[0]);
      my_putstr(" base ops \"()+-*/%\" exp_len\n");
      return (1);
    }
  check_base(av[1]);
  check_ops(av[2]);
  debug = (ac == 5 && my_atoi(av[4]) == 1) ? 1 : 0;
  expr = get_expr(my_atoi(av[3]));
  expr_ok = (my_get_char_pos(&av[2][2], expr[my_strlen(expr) - 1]) == -1);
  if (!expr_syntax(expr, av[2], av[1]) || !expr_ok)
    {
      my_putstr(SYNTAXE_ERROR_MSG);
      return (6);
    }
  my_putstr(eval_expr(av[1], av[2], expr, debug));
  return (0);
}

static void	check_base(char *b)
{
  if (my_strlen(b) < 2 || !my_check_uniq_char(b))
    {
      my_putstr("Bad base\n");
      exit(1);
    }
}

static char	*get_expr(unsigned int size)
{
  char		*expr;

  if (size <= 0)
    {
      my_putstr("Bad expr len\n");
      exit(2);
    }
  expr = malloc(size + 1);
  if (expr == 0)
    {
      my_putstr("could not alloc\n");
      exit(3);
    }
  if (read(0, expr, size) != size)
    {
      my_putstr("could not read\n");
      exit(4);
    }
  expr[size] = 0;
  return (expr);
}

static void	check_ops(char *ops)
{
  if (my_strlen(ops) != 7 || !my_check_uniq_char(ops))
    {
      my_putstr("Bad ops\n");
      exit(5);
    }
}
