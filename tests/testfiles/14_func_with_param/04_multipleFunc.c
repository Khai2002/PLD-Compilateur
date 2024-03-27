int z()
{
    return 1;
}

char donne(char a, int b)
{
    return a + b;
}

int main()
{
    int x;
    x = z();
    if (x == donne('a', 'b'))
    {
        x = 3;
    }
    else
    {
        x = donne('a', 'b');
    }

    return x;
}