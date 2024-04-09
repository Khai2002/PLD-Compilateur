
char a(int z)
{
    int a = 3;
    return a + x() / z;
}

int x()
{
    return 3 * 5;
}


int main()
{
    return a(3);
    //this compiler does return an error because  a() is declared before x() 
    //this normally returns a warning in modern C but in our case we should always have
    // the functions implemented before using them

}