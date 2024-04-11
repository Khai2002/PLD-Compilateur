int main()
{
    int n,i = 3, count = 2, c = 0;

    n = 5;

    if(n == 1) return 2;
    
    while(!(count > n))  
    {
        c = 2;
        while(c < i)
        {
            if (i % c == 0) { // not prime
                c = i + 1; // jump out loop
            } else {
                c++;
            }
        }

        if(c == i) // prime
        {
            count++;
        }

        i++;
    }

    return i - 1;
}