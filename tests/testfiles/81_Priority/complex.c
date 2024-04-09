int main()
{
    int x = 4, y = 5, z = 6;
    x += y * (z - 2) > 10;
    y -= x / 2 < 3 | z % 3 == 0;
    return x + y + z;
}