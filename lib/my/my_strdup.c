/*
** my_strdup.c for my_strdup in /home/bongol_b/rendu/Piscine_C_J08/ex_01
** 
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
** 
** Started on  Wed Oct  7 13:36:20 2015 berdrigue bongolo-beto
** Last update Thu Oct  8 12:46:33 2015 berdrigue bongolo-beto
*/

#include<stdlib.h>

char	*my_strdup(char *src)
{
  char	*src_cp;
  int	src_len;

  src_len = my_strlen(src);
  src_cp = malloc((src_len + 1));
  if (src_cp == NULL)
    return (0);
  my_strcpy(src_cp, src);
  src_cp[src_len] = 0;
  return (src_cp);
}
