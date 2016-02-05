/*
** bistromathique.h for bistromathique in /home/bongol_b/rendu/Piscine_C_bistromathique/include
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Oct 25 15:37:56 2015 berdrigue bongolo-beto
** Last update Sun Nov  1 15:46:30 2015 berdrigue bongolo-beto
*/

#ifndef BISTROMATHIQUE_H_
# define BISTROMATHIQUE_H_

#define OP_OPEN_PARENT_IDX 0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX 2
#define OP_SUB_IDX 3
#define OP_NEG_IDX 3
#define OP_MULT_IDX 4
#define OP_DIV_IDX 5
#define OP_MOD_IDX 6

#define SYNTAXE_ERROR_MSG "syntax error"

typedef struct	s_bistro
{
  char		*base;
  char		*ops;
  char		*expr;
  char		*expr_bak;
  int		size;
  char		*token;
  int		token_idx;
  int		debug;
}		t_bistro;

typedef	struct	s_number
{
  char		*str;
  int		sign;
  int		length;
  int		nz;
  int		idx;
}		t_number;

typedef	struct	s_operation
{
  t_number	n1;
  t_number	n2;
  t_number	res;
  int		sign;
  t_number	tmp;
}		t_operation;

char	*eval_expr(char *base, char *ops, char *expr, int debug);
int	check_parenthesis(char *expr, char *ops);
int	expr_syntax(char *expr, char *ops, char *base);
char	*clean_expr(t_bistro *bistro);
void	get_correct_sign(t_bistro *bistro, int *i, int *j, char *new_expr);
void	get_correct_nbr(t_bistro *bistro, int *i, int *j, char *new_expr);
int	check_op_priority(char op1, char op2, char *ops);
int	is_ops(char *ops, char c, int flag);
void	get_nbr_with_sign(t_bistro *bistro, int *i, int *j, char *output);
char	*rpn_calc(char *output, t_bistro *bistro);
int	is_ops(char *ops, char c, int flag);
char	*expr_to_rpn(t_bistro *bistro, char *output);
char	*infin_add(char *n1, char *n2, t_bistro *bistro);
char	*infin_sub(char *n1, char *n2, t_bistro *bistro, int flag);
char	*infin_mult(char *n1, char *n2, t_bistro *bistro);
char	*infin_div(char *n1, char *n2, t_bistro *bistro);
char	*infin_mod(char *n1, char *n2, t_bistro *bistro);

#endif /* !BISTROMATHIQUE_H_ */
