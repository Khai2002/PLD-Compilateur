int main()
{
    int a, b = 0, c = 0, s = 0;
    
    a = 12321;

    c = a;

    while (a > 0)
    {
        b = a % 10;
        s = (s * 10) + b;
        a = a / 10;
    }

    if (s == c)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}