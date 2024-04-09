int doubleValue(int x)
{
    return 2 * x;
}

int main()
{
    int a = 4;
    a += doubleValue(a += 2);
    return a;
}