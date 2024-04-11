int fibonacci(int num)
{
   int a, b, c, i = 3;
   a = 0;
   b = 1;
   if (num == 1) return 1;

   while(!(i > num))
   {
      c = a+b;
      a = b;
      b = c;
      i++;
   }
   return c;
}

int main()
{
    int num = 10;
    return fibonacci(num);
}
