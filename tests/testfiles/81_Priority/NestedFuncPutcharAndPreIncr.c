#include <stdio.h>

int add(int n)
{
    return n + 1;
}

int main()
{
    int a = 'a';
    return add(putchar(++a));
}
