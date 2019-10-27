/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** testd
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr_neg(int *nb, _Bool *over)
{
    if (*nb < 0) {
        my_putchar('-');
        if (*nb == -2147483648) {
            *nb += 1;
            *over = 1;
        }
        *nb = (*nb * (-1));
    }
}

int my_put_nbr(int nb)
{
    int a;
    int b;
    _Bool over = 0;

    my_put_nbr_neg(&nb, &over);
    if (nb >= 10) {
        my_put_nbr (nb / 10);
        a = (nb % 10 + '0');
        if (over == 1 && a == '7') {
            a++;
            over = 0;
        }
        my_putchar(a);
    } else {
        b = (nb + 48);
        my_putchar(b);
    }
    return 0;
}
