int main()
{
    int x;
    x = 41;
    int y;

    putchar(x = y = x + 1);
    putchar(x = y = x + 1);
    putchar(x = y = x + 1);

    y = y - 1;
    return x;
}