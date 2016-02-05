/*
** my_strlcat.c for my_strlcat in /home/bongol_b/rendu/Piscine_C_J07/ex_07
** 
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
** 
** Started on  Wed Oct  7 21:40:49 2015 berdrigue bongolo-beto
** Last update Sat Oct 17 13:35:53 2015 berdrigue bongolo-beto
*/

int	my_strlcat(char *dest, char *src, int size)
{
  int	i;
  int	dest_len;

  i = 0;
  dest_len = my_strlen(dest);
  while (src[i])
    {
      if ((size - 1) > dest_len)
	dest[dest_len] = src[i];
      dest_len = dest_len + 1;
      i = i + 1;
    }
  dest[dest_len - 1] = 0;
  return (dest_len);
}
