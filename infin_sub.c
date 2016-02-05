/*
** infin_sub.c for infin_sub in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Oct 30 18:00:09 2015 berdrigue bongolo-beto
** Last update Sun Nov  1 20:42:59 2015 berdrigue bongolo-beto
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

int	init_number_sub(t_number *t_nbr, char *str, char *str2, t_bistro *bistro)
{
  int	i;

  if ((t_nbr->str = malloc(corr_maxlen(str, str2, bistro) + 1)) == NULL)
    return (0);
  if (str[0] == bistro->ops[3])
    {
      t_nbr->length = my_strlen(&str[1]);
      my_strncpy(t_nbr->str, &str[1], t_nbr->length + 1);
      t_nbr->sign = -1;
    }
  else
    {
      t_nbr->length = my_strlen(str);
      my_strncpy(t_nbr->str, str, t_nbr->length + 1);
      t_nbr->sign = 1;
    }
  my_revstr(t_nbr->str);
  i = t_nbr->length;
  while (i < corr_maxlen(str, str2, bistro))
    {
      t_nbr->str[i] = bistro->base[0];
      i = i + 1;
    }
  return (1);
}

int	init_operation_sub(t_operation *op, char *n1, char *n2, t_bistro *bistro)
{
  int	init_n1;
  int	init_n2;

  init_n1 = init_number_sub(&op->n1, n1, n2, bistro);
  init_n2 = init_number_sub(&op->n2, n2, n1, bistro);
  if (!init_n1 || !init_n2)
    {
      free(op->n1.str);
      free(op->n2.str);
      return (0);
    }
  op->res.length = my_get_str_maxlen(n1, n2);
  op->res.str = malloc(op->res.length + 1);
  if (op->res.str == NULL)
    return (0);
  op->res.idx = 0;
  return (1);
}

void	subtraction(t_operation *op, char *base)
{
  int	ret;
  int	res;
  int	n1;
  int	n2;

  res = 0;
  ret = 0;
  while (op->res.idx < op->res.length)
    {
      n1 = my_get_char_pos(base, op->n1.str[op->res.idx]);
      n2 = my_get_char_pos(base, op->n2.str[op->res.idx]);
      if ((n2 + ret) > n1)
	{
	  res = (n1 + my_strlen(base) - (n2 + ret));
	  ret = 1;
	}
      else
	{
	  res = (n1 - (n2 + ret));
	  ret = 0;
	}
      op->res.str[op->res.idx] = base[res % my_strlen(base)];
      op->res.idx = op->res.idx + 1;
    }
  op->res.str[op->res.idx] = 0;
}

char		*infin_sub(char *n1, char *n2, t_bistro *bistro, int flag)
{
  char		*tmp_res;
  char		*base;
  char		*ops;

  base = bistro->base;
  ops = bistro->ops;
  tmp_res = my_itoa(my_getnbr_base(n1, base) - my_getnbr_base(n2, base));
  if (my_get_str_maxlen(n1, n2) < 10)
    return (convert_base(tmp_res, "0123456789", base));
  return ("0");
}
