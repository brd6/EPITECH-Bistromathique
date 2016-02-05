/*
** infin_add.c for infin_add in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Oct 30 17:23:03 2015 berdrigue bongolo-beto
** Last update Sun Nov  1 20:42:21 2015 berdrigue bongolo-beto
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

int	init_number(t_number *t_nbr, char *str, int max_len, char *base)
{
  int	i;

  t_nbr->str = malloc(max_len + 1);
  if (t_nbr->str == NULL)
    return (0);
  t_nbr->length = my_strlen(str);
  my_strncpy(t_nbr->str, str, t_nbr->length + 1);
  my_revstr(t_nbr->str);
  i = t_nbr->length;
  while (i < max_len)
    {
      t_nbr->str[i] = base[0];
      i = i + 1;
    }
  return (1);
}

int	init_operation(t_operation *op, char *n1, char *n2, char *base)
{
  int	init_n1;
  int	init_n2;

  init_n1 = init_number(&op->n1, n1, my_get_str_maxlen(n1, n2), base);
  init_n2 = init_number(&op->n2, n2, my_get_str_maxlen(n1, n2), base);
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

void	addition(t_operation *op, char *base)
{
  int	ret;
  int	res;

  ret = 0;
  res = 0;
  while (op->res.idx < op->res.length)
    {
      res = my_get_char_pos(base, op->n1.str[op->res.idx]);
      res = res + my_get_char_pos(base, op->n2.str[op->res.idx]) + ret;
      ret = res / my_strlen(base);
      op->res.str[op->res.idx] = base[res % my_strlen(base)];
      op->res.idx = op->res.idx + 1;
    }
  if (ret > 0)
    {
      op->res.str[op->res.idx] = base[ret];
      op->res.idx = op->res.idx + 1;
    }
  op->res.str[op->res.idx] = 0;
  my_revstr(op->res.str);
}

char		*infin_add(char *n1, char *n2, t_bistro *bistro)
{
  t_operation	op;
  int		i;
  char		*tmp_res;
  char		*base;
  char		*ops;

  base = bistro->base;
  ops = bistro->ops;
  tmp_res = my_itoa(my_getnbr_base(n1, base) + my_getnbr_base(n2, base));
  if (my_get_str_maxlen(n1, n2) < 10)
    return (convert_base(tmp_res, "0123456789", base));
  i = 0;
  if (!init_operation(&op, n1, n2, base))
    return ("0");
  addition(&op, base);
  while (op.res.str[i] == bistro->base[0] &&
	 op.res.str[i] != '\0' && op.res.str[i + 1] != '\0')
    i = i + 1;
  return (&op.res.str[i]);
}
