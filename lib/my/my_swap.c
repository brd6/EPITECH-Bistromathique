/*
** my_swap.c for my_swap in /home/bongol_b/rendu/Piscine_C_J04
** 
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
** 
** Started on  Thu Oct  1 08:53:42 2015 berdrigue bongolo-beto
** Last update Thu Oct  1 08:57:37 2015 berdrigue bongolo-beto
*/

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
  return (0);
}
