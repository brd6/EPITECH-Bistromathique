/*
** infin_sub_utils.c for infin_sub_utils in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Oct 31 00:37:23 2015 berdrigue bongolo-beto
** Last update Sun Nov  1 20:43:07 2015 berdrigue bongolo-beto
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

int	nbr_with_sign_cmp(char *nbr1, char *nbr2, char *ops)
{
  char		*tmp1;
  char		*tmp2;
  int		same_len;
  int		test_len;

  tmp1 = (nbr1[0] == ops[3] ? &nbr1[1] : nbr1);
  tmp2 = (nbr2[0] == ops[3] ? &nbr2[1] : nbr2);
  same_len = my_strlen(tmp1) == my_strlen(tmp2);
  test_len =  my_strlen(tmp1) < my_strlen(tmp2);
  return ((same_len && my_strcmp(tmp1, tmp2) < 0) || test_len);
}

int	corr_maxlen(char *str, char *str2, t_bistro *bistro)
{
  int	max_len;

  max_len = my_get_str_maxlen(str, str2);
  if (str[0] == bistro->ops[3] || str2[0] == bistro->ops[3])
    max_len = my_get_str_maxlen(str, str2) - 1;
  return (max_len);
}
