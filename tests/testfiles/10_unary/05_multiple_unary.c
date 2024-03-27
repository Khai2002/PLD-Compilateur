int main()
{
    int x;
    x = 45;
    int y;
    y = 2;
    int e;
    e = !!x + !-y + -!x + --y;
    return e;
}