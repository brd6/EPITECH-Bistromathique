/*
** mylist.h for mylist in /home/bongol_b/rendu/Piscine_C_J11
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Oct 12 09:29:09 2015 berdrigue bongolo-beto
** Last update Fri Oct 30 10:17:14 2015 berdrigue bongolo-beto
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct	s_list
{
  char		*data;
  struct s_list	*next;
}		t_list;

void    *stack_pop(t_list **stack);
int	stack_push(t_list **stack, void *data);
void	stack_show(t_list *stack, char type);
void	*stack_top(t_list *stack);

#endif /* !MYLIST_H_ */
