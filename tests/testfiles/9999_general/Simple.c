int main()
{
    int x = 5;
    while ((x = getchar()) != '\n')
    {
        x--;
    }
    putchar(x);
    return x++;
}