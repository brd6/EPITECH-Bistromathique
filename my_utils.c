/*
** my_utils.c for my_utils in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Oct 25 15:11:29 2015 berdrigue bongolo-beto
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

void	get_correct_nbr(t_bistro *bistro, int *i, int *j, char *new_expr)
{
  while (my_get_char_pos(bistro->base, bistro->expr[*i]) != -1)
    {
      new_expr[*j] = bistro->expr[*i];
      *j = *j + 1;
      *i = *i + 1;
    }
  *i = *i - 1;
}

void	get_correct_sign(t_bistro *bistro, int *i, int *j, char *new_expr)
{
  int	sign;
  int	i_bak;

  sign = 1;
  i_bak = *i;
  while (is_ops(bistro->ops, bistro->expr[*i], 0))
    {
      if (bistro->expr[*i] == bistro->ops[3])
	sign = sign * (-1);
      *i = *i + 1;
    }
  if ((i_bak == 0 && sign == -1) || i_bak != 0)
    {
      new_expr[*j] = (sign == 1) ? bistro->ops[2] : bistro->ops[3];
      *j = *j + 1;
    }
  *i = *i - 1;
}

char	*clean_expr(t_bistro *bistro)
{
  int	i;
  int	j;
  char	*new_expr;

  i = 0;
  j = 0;
  if ((new_expr = malloc(bistro->size + 1)) == NULL)
    return (NULL);
  while (bistro->expr[i])
    {
	if (is_ops(bistro->ops, bistro->expr[i], 0))
	  get_correct_sign(bistro, &i, &j, new_expr);
	else if (my_get_char_pos(bistro->base, bistro->expr[i]) != -1)
	  get_correct_nbr(bistro, &i, &j, new_expr);
	else
	  {
	    new_expr[j] = bistro->expr[i];
	    j = j + 1;
	  }
      i = i + 1;
    }
  new_expr[j] = 0;
  return (new_expr);
}

int	my_get_str_maxlen(char *str1, char *str2)
{
  int	str1_len;
  int	str2_len;

  str1_len = my_strlen(str1);
  str2_len = my_strlen(str2);
  return (str1_len > str2_len ? str1_len : str2_len);
}
