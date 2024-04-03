int main()
{
    int x;
    x = 3;
    if (x++)
    {
        x = x++ + 4;
    }
    x = x++;
    return (x)--;
}