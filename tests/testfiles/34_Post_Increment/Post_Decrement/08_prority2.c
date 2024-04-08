int main()
{
    int x = 3;
    int y = 4;
    int w = 1;
    int z = x++ * 3 % y-- + (x = 4) / ++w;
    return z;
}