int main()
{
    int x = 3;
    int z = 'z';
    int s = 1;
    int a = x++ * (s -= --x);
    // here the test fails this increments and decrements the same variable in the same line
    return a;
}
