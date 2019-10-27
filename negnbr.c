/*
** EPITECH PROJECT, 2019
** d
** File description:
** d
*/

#include <stdlib.h>
#include "include/eval_expr.h"

int isnum_neg(char *calc, int *num, int pos)
{
    int i;
    int popo = 0;
    if (calc[0] == '-')
        num[popo] *= (-1);
    for (i = 1; calc[i] != '\0'; i++) {
        if (calc[i] >= '0' && calc[i] <= '9') {
            if ((calc[(i - 1)] == '-') && (calc[(i - 2)] == '*'
                || calc[(i - 2)] == '/' || calc[(i - 2)] == '+'
                || calc[(i - 2)] == '-' || calc[(i - 2)] == '%')) {
                if (num[0] < 0)
                    num[popo] *= (-1);
                else if (num[0] >= 0) {
                    num[popo] *= (-1);
                }
                popo++;
            }
            else
                popo++;
            while (calc[i] >= '0' && calc[i] <= '9')
                i++;
            i--;
        }
    }
}

int pre_clac_fork(char *calc, int len)
{
    int *num;
    int i;
    int pos = 0;
    int signes = 0;
    char *op;
    int res;

    nbr_signes(calc, &signes);
    num = (int *)malloc((signes + 1) * sizeof(int));
    op = (char *)malloc((signes + 1) * sizeof(char));
    op[signes] = '\0';
    put_zero(num, (signes + 1));
    for (i = 0 ; calc[i] != '\0'; i++) {
        if (calc[i] >= '0' && calc[i] <= '9')
            num[pos] = ((num[pos] * 10) + (calc[i] - '0'));
        if (calc[(i + 1)] == '+' || calc[(i + 1)] == '-'
            || calc[(i + 1)] == '*' || calc[(i + 1)] == '/'
            || calc[(i + 1)] == '%') {
            op[pos] = calc[(i + 1)];
            pos++;
            i++;
            }
    }
    isnum_neg(calc, num, pos);
    return calc_fork(num, op, signes);
}