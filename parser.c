/*
** EPITECH PROJECT, 2019
** bootstrap-evalexpr
** File description:
** le parsing ça passe
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/eval_expr.h"

void find_bra(char *str, int *first_close_bra, _Bool *find, int *last_open_bra)
{
    int i;
    int len;

    for (len = 0; str[len] != '\0'; len++);
    for (i = 0; i < len; i++) {
        if (str[i] == ')' && *find == 0) {
            *first_close_bra = i;
            *find = 1;
        }
    }
    *find = 0;
    for (i = *first_close_bra; i >= 0; i--) {
        if (str[i] == '(' && *find == 0) {
            *last_open_bra = i;
            *find = 1;
        }
    }
}

char *brackets(char *str, int len)
{
    int i;
    int j = 0;
    int first_close_bra = -1;
    _Bool find = 0;
    int last_open_bra = -1;
    char *calc;
    int res;

    find_bra(str, &first_close_bra, &find, &last_open_bra);
    if (first_close_bra == -1)
        return str;
    calc = (char *)malloc((first_close_bra - last_open_bra) * sizeof(char));
    calc[(first_close_bra - last_open_bra - 1)] = '\0';
    for (i = (last_open_bra + 1); i <= (first_close_bra - 1); i++) {
        calc[j] = str[i];
        j++;
    }
    res = pre_clac_fork(calc, (last_open_bra - first_close_bra - 1));
    for (i = last_open_bra; i <= first_close_bra; i++) {
        str[i] = 'a';
    }
    str = replace_str(str, res);
    if (first_close_bra != -1)
        brackets(str, len);
}

int parser_comme_jaja(const char *str)
{
    int i;
    int len;
    char *res;
    char *stt;
    int result = 0;
    _Bool neg = 0;

    for (len = 0; str[len] != '\0'; len++);
    res = (char *)malloc((len + 3) * sizeof(char));
    res[0] = '(';
    res[(len + 1)] = ')';
    res[(len + 2)] = '\0';
    for (i = 0; str[i] != '\0'; i++)
        res[i + 1] = str[i];
    stt = brackets(res, len);
    for (i = 0; stt[i] != '\0'; i++) {
        if (stt[0] == '-' && neg == 0) {
            neg = 1;
            i++;
        }
        result = ((result * 10) + (stt[i] - '0'));
        }
        if (neg == 1)
            result *= (-1);
    return result;
}

int eval_expr(char const *str)
{
    int i;
    int brackets = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            brackets++;
        else if (str[i] == ')')
            brackets--;
    }
    if (brackets != 0)
        return 84;
    return parser_comme_jaja(str);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}