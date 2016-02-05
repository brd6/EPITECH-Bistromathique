/*
** my_strncpy.c for my_strncpy in /home/bongol_b/rendu/Piscine_C_J06
** 
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
** 
** Started on  Mon Oct  5 10:15:33 2015 berdrigue bongolo-beto
** Last update Tue Oct  6 21:00:52 2015 berdrigue bongolo-beto
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (n > i)
    dest[i] = 0;
  return (dest);
}
