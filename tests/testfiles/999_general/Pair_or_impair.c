int main()
{
    char c;
    int num = 0;

    while ((c = getchar()) != 'a')
    {
        if (c > '0')
        {
            if (c < '9')
            {
                num = num * 10 + (c - '0');
            }
        }
    }
    if (num % 2 == 0)
    {
        putchar('P');
    }
    else
    {
        putchar('I');
    }
}