/*
** my_strncmp.c for my_strncmp in /home/bongol_b/rendu/Piscine_C_J06
** 
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
** 
** Started on  Mon Oct  5 15:35:26 2015 berdrigue bongolo-beto
** Last update Tue Oct  6 21:03:49 2015 berdrigue bongolo-beto
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && i < n)
    {
      if (!s2[i])
	return (1);
      if (s2[i] > s1[i])
	return (-1);
      if (s1[i] > s2[i])
	return (1);
      i = i + 1;
    }
  return (0);
}
