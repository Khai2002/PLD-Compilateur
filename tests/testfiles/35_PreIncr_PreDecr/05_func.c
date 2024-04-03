int a(int z, char c)
{
    return z++ * 4 / c;
}
int main()
{
    int x;
    x = 34;
    int w;
    w = a(++x, --x);
    return w;
}