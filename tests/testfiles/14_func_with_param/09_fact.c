int fact(int n)
{
    int x;
    x = n;
    while (n > 1)
    {
        x = x * (n - 1);
        n = n - 1;
    }
    return x;
}
int main()
{
    int a;
    a = 4;
    return fact(a);
}