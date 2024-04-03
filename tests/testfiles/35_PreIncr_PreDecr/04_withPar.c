int main()
{
    int x;
    x = 34;
    (x)--;
    (x)--;
    int a;
    a = (x)++ * 3 % 4;
    if (x++)
    {
        a++;
    }
    return a;
}