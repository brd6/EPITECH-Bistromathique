/*
** my_str_isalpha.c for my_str_isalpha in /home/bongol_b/rendu/Piscine_C_J06
** 
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
** 
** Started on  Mon Oct  5 16:39:23 2015 berdrigue bongolo-beto
** Last update Mon Oct  5 16:52:52 2015 berdrigue bongolo-beto
*/

int	is_alpha(char c)
{
  return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	my_str_isalpha(char *str)
{
  while (*str && is_alpha(*str))
      str = str + 1;
  return (!(*str));
}
