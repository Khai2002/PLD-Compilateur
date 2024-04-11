int isPrime(int i)
{
    int c = 2;
    while(c < i)
    {
        if (i % c == 0) {
            return 0;
        } else {
            c++;
        }
    }
    return 1;
}

int main()
{
    int n,i = 3, count = 1;

    n = 5;

    if(n == 1) return 2;
    
    while(count < n) {
        if(isPrime(i)) {
            count++;
        }
        i++;
    }

    return i - 1;
}