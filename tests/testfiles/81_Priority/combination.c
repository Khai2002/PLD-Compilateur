int doubleIt(int x)
{
    return 2 * x;
}

int main()
{
    int a = 5;
    a += doubleIt(a) & a % 3 == 0; // Combines function call, logical AND, and modulo
    return a;
}