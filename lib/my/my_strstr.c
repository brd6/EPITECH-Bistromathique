/*
** my_strstr.c for my_strstr in /home/bongol_b/rendu/Piscine_C_J06
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct  5 13:03:13 2015 berdrigue bongolo-beto
** Last update Sat Oct 17 17:50:03 2015 berdrigue bongolo-beto
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == to_find[j])
	j = j + 1;
      else
	j = 0;
      if (to_find[j] == 0)
	{
	  i = i - (j - 1);
	  return (str + i);
	}
      i = i + 1;
    }
  return (0);
}
