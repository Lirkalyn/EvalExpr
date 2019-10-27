/*
** EPITECH PROJECT, 2019
** bootstrap-evalexpr
** File description:
** just put 0 LOL
*/

#include "include/eval_expr.h"

int factor(int *num, char operand, int signes, int pos)
{
    int i;

    if (operand == '*')
        num[pos] = (num[pos] * num[(pos + 1)]);
    else if (operand == '/')
        num[pos] = (num[pos] / num[(pos + 1)]);
    else
        num[pos] = (num[pos] % num[(pos + 1)]);
}

int sum(int *num, char operand, int signes, int pos)
{
    if (operand == '+')
        num[0] = (num[(0)] + num[1]);
    else if (operand == '-')
        num[0] = (num[(0)] - num[1]);
}

int calc_fork(int *num, char *op, int signes)
{
    int i;
    int j;
    int si = signes;

    for (i = 0; i < si; i++) {
        if (op[i] == '*' || op[i] == '/' || op[i] == '%') {
            factor(num, op[i], signes, i);
            for (j = i; j < signes; j++) {
                op[j] = op[(j + 1)];
            }
            for (j = (i + 1); j < signes; j++) {
                num[j] = num[(j + 1)];
            }
            signes--;
        i = 0;
        }
    }
    for (i = 0; i < si; i++) {
        if (op[0] == '+' || op[0] == '-') {
            sum(num, op[0], signes, i);
            for (j = 0; j < signes; j++) {
                op[j] = op[(j + 1)];
            }
            for (j = 1; j < signes; j++) {
                num[j] = num[(j + 1)];
            }
            signes--;
            i = 0;
        }
    }
    if (op[0] != '\0')
        calc_fork(num, op, signes);
    return num[0];
}

int nbr_signes(char *calc, int *signes)
{
    int i;

    for (i = 0 ; calc[i] != '\0'; i++) {
        if (calc[i] == '+' || calc[i] == '-'
            || calc[i] == '*' || calc[i] == '/' || calc[i] == '%')
            *signes += 1;
    }
}

void put_zero(int *num,  int len)
{
    int i;

    for (i = 0; i < len; i++) {
        num[i] = 0;
    }
}