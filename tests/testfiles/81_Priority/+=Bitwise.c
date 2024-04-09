int main()
{
    int a = 3;
    int b = 4;
    a += (b++ | 1);
    b -= (a++ & 2); 
    return a + b;
}
