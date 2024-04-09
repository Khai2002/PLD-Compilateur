int isPositive(int x)
{
    return x > 0;
}

int main()
{
    int a = -1, b = 3;
    a += !isPositive(a);
    b -= !isPositive(b);
    return a + b;
}
