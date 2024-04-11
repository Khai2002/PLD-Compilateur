int main()
{
    int i = 0;
    int j = 0;
    int sum = 0;
    while (i < 5)
    {
        j = 1;
        while (j < 5)
        {
            sum++;
            j++;
        }
        i++;
    }
    return sum;
}