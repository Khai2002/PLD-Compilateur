int increment(int x)
{
    return x + 1;
}

int main()
{
    int a = 3;
    int result = increment(a++) + 4;
    return result;
}