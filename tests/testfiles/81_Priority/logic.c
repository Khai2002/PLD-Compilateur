int check(int x)
{
    return x > 5;
}

int main()
{
    int a = 3;
    int b = 7;
    a += check(b);
    return a > 5 & b < 10;
}