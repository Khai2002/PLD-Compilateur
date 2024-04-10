int main()
{
    int a = 4;
    int b = 3;
    a += b--; 
    b -= a++; 
    return a + b;
}