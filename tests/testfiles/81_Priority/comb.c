int main()
{
    int a = 2, b = 3, c = 4;
    a += (b * c++) / (b - --c); // Includes multiplication, division, post-increment, and pre-decrement
    return a + b + c;
}