#include <stdio.h>
int main()
{
    char x, z;
    x = 'z';
    z = putchar(x) + putchar('a');

    return z;
}