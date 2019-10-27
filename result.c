/*
** EPITECH PROJECT, 2019
** bootstrap-evalexpr
** File description:
** just for result
*/

#include <stdlib.h>
#include "include/eval_expr.h"

void fill_new_str(char *str, int res, char *new_str, int res_size)
{
    int i;
    int j;
    int last_a_pos;
    int num_a = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            last_a_pos = i;
            num_a++;
        }
    }
    for (i = 0; i <= (last_a_pos - num_a); i++)
        new_str[i] = str[i];
    if (res < 0) {
        res *= (-1);
        new_str[i] = '-';
        i++;
    }
    for (j = (i + res_size - 1); j >= i; j--) {
        new_str[j] = ((res % 10) + '0');
        res /= 10;
    }
    i += res_size;
    last_a_pos++;
    for (; str[last_a_pos] != '\0'; last_a_pos++) {
        new_str[i] = str[last_a_pos];
        i++;
    }
}

int size_of_res(int res)
{
    int i;

    if (res < 0)
        res *= (-1);
    for (i = 0; res > 0; i++)
        res /= 10;
    return i;
}

char *replace_str(char *str, int res)
{
    int i;
    int res_size;
    int str_size_no_a  = 0;
    char *new_str;

    res_size = size_of_res(res);
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] != 'a')
            str_size_no_a++;
    if (res < 0) {
        new_str = (char *)malloc((res_size + str_size_no_a + 2) * sizeof(char));
        new_str[(res_size + str_size_no_a + 1)] = '\0';
    }
    else {
        new_str = (char *)malloc((res_size + str_size_no_a + 1) * sizeof(char));
        new_str[(res_size + str_size_no_a)] = '\0';
    }
    fill_new_str(str, res, new_str, res_size);
    return new_str;
}
