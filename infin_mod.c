/*
** infin_mod.c for infin_mod in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Oct 30 18:00:52 2015 berdrigue bongolo-beto
** Last update Sun Nov  1 20:41:05 2015 berdrigue bongolo-beto
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

char		*infin_mod(char *n1, char *n2, t_bistro *bistro)
{
  char		*tmp_res;
  char		*base;
  char		*ops;

  base = bistro->base;
  ops = bistro->ops;
  tmp_res = my_itoa(my_getnbr_base(n1, base) % my_getnbr_base(n2, base));
  if (my_get_str_maxlen(n1, n2) < 10)
    return (convert_base(tmp_res, "0123456789", base));
  return ("0");
}
