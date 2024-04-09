int PGCD(int b, int a)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int a = 5, b = 20;
    return PGCD(a, b);
}
