/*
** my_str_split.c for my_str_plit in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Oct 28 21:43:17 2015 berdrigue bongolo-beto
** Last update Thu Oct 29 09:06:18 2015 berdrigue bongolo-beto
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"

int     count_word(char *str, char sp)
{
  int   i;
  int   nb_word;

  i = 0;
  nb_word = 0;

  while(str[i])
    {
      if(str[i] != sp)
        {
          nb_word = nb_word + 1;
          while (str[i] != sp  && str[i])
            {
              i = i + 1;
            }
          i = i - 1;
        }
      i = i + 1;
    }
  return (nb_word);
}

char            **my_str_split(char *str, char sp)
{
  char  **tab;
  int   i;
  int   j;
  int   k;

  k = 0;
  j = 0;
  i = 0;
  tab = malloc(sizeof(*tab) * (count_word(str, sp) + 1));
  while (str[i] != '\0')
    {
      tab[j] =  malloc(sizeof(*tab) * my_strlen(str) + 1);
      while ((str[i] == sp) && str[i] != '\0')
        i = i + 1;
      while (str[i] != sp && str[i] != '\0')
        {
          tab[j][k] = str[i];
          i = i + 1;
          k = k + 1;
        }
      tab[j][k] = '\0';
      k = 0;
      j = j + 1;
    }
  tab[j] = 0;
  return (tab);
}
