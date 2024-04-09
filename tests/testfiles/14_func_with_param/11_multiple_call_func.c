

int x()
{
    return 3 * 5;
}

char a(int z)
{
    int a = 3;
    return a + x() / z;
}

int main()
{
    return a(3);
}