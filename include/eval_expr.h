/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** all functions
*/


#ifndef MY_H_
#define MY_H_

char *brackets(char *str, int len);
int parser_comme_jaja(const char *str);
int isnum_neg(char *calc, int *num, int pos);
int pre_clac_fork(char *calc, int len);
int factor(int *num, char operand, int signes, int pos);
int sum(int *num, char operand, int signes, int pos);
int calc_fork(int *num, char *op, int signes);
int nbr_signes(char *calc, int *signes);
void put_zero(int *num,  int len);
void fill_new_str(char *str, int res, char *new_str, int res_size);
int size_of_res(int res);
char *replace_str(char *str, int res);
void my_putchar(char c);
int my_put_nbr(int nb);

#endif