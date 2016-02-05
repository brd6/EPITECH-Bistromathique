/*
** stack_show.c for stack_show in /home/bongol_b/rendu/Piscine_C_bistromathique
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Oct 27 22:32:15 2015 berdrigue bongolo-beto
** Last update Fri Oct 30 10:25:08 2015 berdrigue bongolo-beto
*/

#include "../../include/my.h"

void	stack_show(t_list *stack, char type)
{
  t_list	*curr;

  curr = stack;
  while (curr && curr->data != 0)
    {
      my_putchar('[');
      if (type == 's')
	my_putstr((char *)curr->data);
      else if (type == 'c')
	my_putchar(*((char*)curr->data));
      else if (type == 'i')
	my_put_nbr((*(int *)curr->data));
      my_putstr("]\n");
      curr = curr->next;
    }
}
