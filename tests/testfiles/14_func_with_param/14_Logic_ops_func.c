int isEven(int x)
{
    return x % 2 == 0;
}

int main()
{
    int a = 4;
    int result = isEven(a) & a > 2;
    return result;
}