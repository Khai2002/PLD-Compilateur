int main()
{
    int x = 4;
    int z = 'z';
    int s = 1;
    int a = x++ * (s -= --x);
    return a;
}
